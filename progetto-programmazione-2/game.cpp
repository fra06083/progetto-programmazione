
#include "game.hpp"
Game::Game(Layout *l, Map *m, Player *p, p_en en, p_pro pr)
{
    this->layout = l;
    this->map = m;
    this->player = p;
    this->enemy = en;
    this->proiettile= pr;
        
    
}
int Game::updateJump(WINDOW* game, Player *p, Map *map, bool isJump, int i){

    if(i<=player->jump_max && !map->platformAbove(p->x, p->y) && !(p->y == 0)) {  // Interrompi il salto se c'è una piattaforma sopra. 
        p->y=p->y-1;
        i=i+1;
        mvwaddch(game, p->y + 1, p->x, ' ');
        wrefresh(game);
        
        mvwaddch(game, p->y, p->x, '@');
        wrefresh(game);

    }
    else{
        player->isJumping=false;
        this->counter=0;
        i=0;
    }
    return i;
    }

   

void Game::run()
{
    // Inizializza lo schermo di gioco
    layout->init_screen();

    // Mostra il menu principale e ottieni la scelta dell'utente
    int scelta = layout->main_menu();

    if (scelta)
    {
        clear();

        // Se la scelta è 1, inizia una nuova partita
        if (scelta == 1)
        {
            // Genera la mappa di gioco
            map->generateMap();

            // Inizializza il giocatore
            player->init();

            bool game_over = false;
            char p_direction = 'r'; // Inizializzazione direzione proiettile
            int counter_nemici = 100;
            std::srand(std::time(0));

            // Loop principale del gioco
            while (!quit)
            {
                // Imposta la modalità di attesa per l'input
                halfdelay(1);

                clear();

                // Disegna la mappa
                for (int i = 0; i < MAX_X; i++)
                {
                    for (int j = 0; j < MAX_Y; j++)
                    {
                        if (map->isPlatform(i, j))
                        {
                            move(j, i);
                            mvwprintw(layout->game, j, i, "=");
                        }
                    }
                }

                // Disegna il bordo del gioco
                layout->draw_box();

                // Disegna il giocatore
                player->draw(layout->game);

                // Aggiungi un nemico ogni 100 iterazioni
                if (counter_nemici == 100)
                {
                    int en_X = std::rand() % 79;
                    int en_Y = std::rand() % 23;
                    Nemico *en = new Nemico(en_X, en_Y);
                    enemy = e_head_insert(enemy, en);
                    enemy->enemy->draw(layout->game);
                    counter_nemici = 0;
                }

                counter_nemici = counter_nemici + 1;
                std::cerr << counter_nemici;

                // Aggiorna la posizione e disegna i nemici vivi
                if (enemy != NULL)
                {
                    p_en count = enemy;
                    p_en prev = NULL;

                    while (count != NULL)
                    {
                        if (!count->enemy->dead)
                        {
                            count->enemy->move(layout->game, map, player->x, player->y);
                            count->enemy->draw(layout->game);
                            prev = count;
                            count = count->next;
                        }
                        else
                        {
                            // Rimuovi il nemico morto dalla lista
                            if (prev != NULL)
                            {
                                prev->next = count->next;
                                delete count->enemy;
                                delete count;
                                count = prev->next;
                            }
                            else
                            {
                                enemy = count->next;
                                delete count->enemy;
                                delete count;
                                count = enemy;
                            }
                        }
                    }

                    // Rimuovi i nemici morti
                    enemy = e_tail_delete(enemy, map, proiettile);
                }

                // Aggiorna lo schermo
                wrefresh(layout->game);

                // Gestisci i proiettili
                if (proiettile != NULL)
                {
                    p_pro count = proiettile;
                    while (count != NULL)
                    {
                        if (count->pro->isAttivo())
                        {
                            count->pro->move(layout->game, proiettile, count->pro->dir);
                        }
                        count = count->next;
                    }

                    // Rimuovi i proiettili
                    proiettile = tail_delete(proiettile, map);
                }

                // Gestisci l'input dell'utente
                int ch = getch();
                if (ch == ' ')
                {
                    // Sparo di un proiettile
                    Proiettile *p = new Proiettile(player->x, player->y);
                    p->spara();
                    p->dir = p_direction;
                    proiettile = head_insert(proiettile, p);
                    proiettile->pro->draw(layout->game, player->x, player->y);

                    wrefresh(layout->game);
                }
                if (ch == 'a' || ch == 'A' || ch == KEY_LEFT)
                {
                    // Movimento a sinistra del giocatore
                    player->p_move(layout->game, 'l');
                    p_direction = 'l';
                }
                if (ch == 'd' || ch == 'D' || ch == KEY_RIGHT)
                {
                    // Movimento a destra del giocatore
                    player->p_move(layout->game, 'r');
                    p_direction = 'r';
                }
                if ((ch == 'w' || ch == 'W' || ch == KEY_UP) && (!player->fall && !player->isJumping))
                {
                    // Inizia il salto se il giocatore non è già in salto o cadendo
                    player->isJumping = true;
                }
                if (ch == 'e')
                {
                    // Esci dal gioco
                    quit = true;
                }
                if (map->platformUnder(player->x, player->y))
                    player->fall = false;
                if (!player->isJumping && !map->platformUnder(player->x, player->y))
                {
                    // Se il giocatore non sta saltando e non è su una piattaforma, sta cadendo
                    player->fall = true;
                    player->y++;
                }
                if (player->isJumping && !player->fall)
                {
                    // Aggiorna la fase di salto del giocatore
                    this->counter = updateJump(layout->game, player, map, player->isJumping, this->counter);
                }
            }
        }

        // Aggiorna lo schermo principale
        refresh();
        // Termina la modalità NCurses
        endwin();
    }
}
