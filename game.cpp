
#include "game.hpp"
Game::Game(Layout *l, Map *m, Player *p, p_base_en b_en, p_medium_en m_en, p_tough_en t_en, p_pro pr)
{
    this->layout = l;
    this->map = m;
    this->player = p;
    this->base_en = b_en;
    this->medium_en= m_en;
    this->tough_en = t_en;
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
p_base_en Game::b_update_enemy( p_base_en base_en,p_medium_en medium_en, p_tough_en tough_en, WINDOW* game, Map *map, Player *player, p_pro proiettile){
// Aggiorna la posizione e disegna i nemici vivi
                if (base_en != NULL)
                {
                    p_base_en count = base_en;
                    p_base_en prev = NULL;

                    while (count != NULL)
                    {
                        if (!count->b_en->dead)
                        { 
                    
                            int deltaX = player->x - count->b_en->x_;
                            if(deltaX>0 && !Base_isPositionOccupied(count->b_en->x_ + 1,count->b_en->y_, base_en) 
                            && !Medium_isPositionOccupied(count->b_en->x_ + 1,count->b_en->y_, medium_en) 
                            && !Medium_isPositionOccupied(count->b_en->x_ + 1,count->b_en->y_, medium_en)){
                            count->b_en->move(game, map, 'r');
                            }
                            if(deltaX<0 && !Base_isPositionOccupied(count->b_en->x_ - 1,count->b_en->y_, base_en) 
                            && !Medium_isPositionOccupied(count->b_en->x_ - 1,count->b_en->y_, medium_en) 
                            && !Medium_isPositionOccupied(count->b_en->x_ - 1,count->b_en->y_, medium_en)){
                            count->b_en->move(game, map, 'l');
                            }


                            count->b_en->draw(game);                            
                            prev = count;
                            count = count->next;
                        }
                        else
                        {
                            // Rimuovi il nemico morto dalla lista
                            if (prev != NULL)
                            {
                                prev->next = count->next;
                                delete count->b_en;
                                delete count;
                                count = prev->next;
                            }
                            else
                            {
                                base_en = count->next;
                                delete count->b_en;
                                delete count;
                                count = base_en;
                            }
                        }
                    }

                    // Rimuovi i nemici morti
                    base_en = e_tail_delete(base_en, map, proiettile, player);
                }
                return base_en;
}
p_medium_en Game::m_update_enemy( p_base_en base_en,p_medium_en medium_en, p_tough_en tough_en, WINDOW* game, Map *map, Player *player, p_pro proiettile){
// Aggiorna la posizione e disegna i nemici vivi
                if (medium_en != NULL)
                {
                    p_medium_en count = medium_en;
                    p_medium_en prev = NULL;

                    while (count != NULL)
                    {
                        if (!count->m_en->dead)
                        { 
                    
                            int deltaX = player->x - count->m_en->x_;
                            if(deltaX>0 && !Base_isPositionOccupied(count->m_en->x_ + 1,count->m_en->y_, base_en) 
                            && !Medium_isPositionOccupied(count->m_en->x_ + 1,count->m_en->y_, medium_en) 
                            && !Medium_isPositionOccupied(count->m_en->x_ + 1,count->m_en->y_, medium_en)){
                            count->m_en->move(game, map, 'r');
                            }
                            if(deltaX<0 && !Base_isPositionOccupied(count->m_en->x_ - 1,count->m_en->y_, base_en) 
                            && !Medium_isPositionOccupied(count->m_en->x_ - 1,count->m_en->y_, medium_en) 
                            && !Medium_isPositionOccupied(count->m_en->x_ - 1,count->m_en->y_, medium_en)){
                            count->m_en->move(game, map, 'l');
                            }


                            count->m_en->draw(game);                            
                            prev = count;
                            count = count->next;
                        }
                        else
                        {
                            // Rimuovi il nemico morto dalla lista
                            if (prev != NULL)
                            {
                                prev->next = count->next;
                                delete count->m_en;
                                delete count;
                                count = prev->next;
                            }
                            else
                            {
                                medium_en = count->next;
                                delete count->m_en;
                                delete count;
                                count = medium_en;
                            }
                        }
                    }

                    // Rimuovi i nemici morti
                    medium_en = e_tail_delete(medium_en, map, proiettile, player);
                }
                return medium_en;
}
p_tough_en Game::t_update_enemy( p_base_en base_en,p_medium_en medium_en, p_tough_en tough_en, WINDOW* game, Map *map, Player *player, p_pro proiettile){
// Aggiorna la posizione e disegna i nemici vivi
                if (tough_en != NULL)
                {
                    p_tough_en count = tough_en;
                    p_tough_en prev = NULL;

                    while (count != NULL)
                    {
                        if (!count->t_en->dead)
                        { 
                    
                            int deltaX = player->x - count->t_en->x_;
                            if(deltaX>0 && !Base_isPositionOccupied(count->t_en->x_ + 1,count->t_en->y_, base_en) 
                            && !Medium_isPositionOccupied(count->t_en->x_ + 1,count->t_en->y_, medium_en) 
                            && !Medium_isPositionOccupied(count->t_en->x_ + 1,count->t_en->y_, medium_en)){
                            count->t_en->move(game, map, 'r');
                            }
                            if(deltaX<0 && !Base_isPositionOccupied(count->t_en->x_ - 1,count->t_en->y_, base_en) 
                            && !Medium_isPositionOccupied(count->t_en->x_ - 1,count->t_en->y_, medium_en) 
                            && !Medium_isPositionOccupied(count->t_en->x_ - 1,count->t_en->y_, medium_en)){
                            count->t_en->move(game, map, 'l');
                            }


                            count->t_en->draw(game);                            
                            prev = count;
                            count = count->next;
                        }
                        else
                        {
                            // Rimuovi il nemico morto dalla lista
                            if (prev != NULL)
                            {
                                prev->next = count->next;
                                delete count->t_en;
                                delete count;
                                count = prev->next;
                            }
                            else
                            {
                                tough_en = count->next;
                                delete count->t_en;
                                delete count;
                                count = tough_en;
                            }
                        }
                    }

                    // Rimuovi i nemici morti
                    tough_en = e_tail_delete(tough_en, map, proiettile, player);
                }
                return tough_en;
}
void Game::drawMap (Layout *game_window, Map *game_map){
    for (int i = 0; i < MAX_X; i++){   
        for (int j = 0; j < MAX_Y; j++){
            if (map->isPlatform(i, j)){

                move(j, i);
                mvwprintw(layout->game, j, i, "=");
                int tempI=i, tempJ=j;

                //Disegna le box (| ? |) sulle piattaforme designate
                for(int v=1; map->isPlatform(tempI++, tempJ); v++){
                    if(v==5){
                        tempI=tempI-v;
                        tempJ++;
                        for(int k=0; map->isPlatform(tempI++, tempJ); k++){
                            if(k>=5 && tempJ != MAX_Y-1){
                                mvwprintw(layout->game, j-2, i+1, "___");
                                mvwprintw(layout->game, j-1, i,  "| ? |");
                            }}
                    }}
            }}
    }}   

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
            rooms=new room(map);
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
                drawMap(layout, map);
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
                if (counter_nemici == 100 && rooms->current_room%5!=0)
                {   int n= std::rand() % 3;
                    
                    if(n==0){
                    int en_X = std::rand() % 79;
                    int en_Y = std::rand() % 23;
                   
                    Base_en *en = new Base_en(en_X, en_Y);
                
                    base_en = e_head_insert(base_en, en);
                    base_en->b_en->draw(layout->game);
                    }
                    if(n==1){
                    int en_X = std::rand() % 79;
                    int en_Y = std::rand() % 23;
                    
                    Medium_en *en = new Medium_en(en_X, en_Y);
                
                    medium_en = e_head_insert(medium_en, en);
                    medium_en->m_en->draw(layout->game);
                    }
                    if(n==2){
                    int en_X = std::rand() % 79;
                    int en_Y = std::rand() % 23;
                    
                    Tough_en *en = new Tough_en(en_X, en_Y);
                
                    tough_en = e_head_insert(tough_en, en);
                    tough_en->t_en->draw(layout->game);
                        
                    }
                    counter_nemici = 0;
                }

                counter_nemici = counter_nemici + 1;
                std::cerr << counter_nemici;
            
                base_en = b_update_enemy(base_en,medium_en,tough_en, layout->game,map, player, proiettile);
                medium_en = m_update_enemy(base_en,medium_en,tough_en, layout->game,map, player, proiettile);
                tough_en = t_update_enemy(base_en,medium_en,tough_en, layout->game,map, player, proiettile);
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
                 // cout temporaneo per guardare i contatori
                cout<<"\n\ncurrent:"<<rooms->current_room<<" last:"<<rooms->last_room<<"-";

                // Caso in cui siamo già nell'ultima stanza generata
                if (player->x==MAX_X-1 && rooms->current_room == rooms->last_room){
                    //Genera e salva nuove mappe
                    map=rooms->generate_new_room(); 

                    //Riporta la x all'inizio alla generazione della nuova mappa
                    player->x=2; 

                    //controlla non ci siano piattaforme e sposta il player di conseguenza
                    if (map->isPlatform(player->y, player->x)){
                        player->y--;
                    }         
                }

                //Caso in cui vogliamo tornare indietro
                if (player->x==1 && rooms->current_room != 1){
                    map=rooms->load_room(rooms->current_room-1);
                    player->x=MAX_X-2;
                    if (map->isPlatform(player->y, player->x)){
                        player->y--;
                    }
                }

                //Caso in cui si va avanti ma non siamo nell'ultima stanza
                if (player->x==MAX_X-1 && rooms->current_room != rooms->last_room){
                    map=rooms->load_room(rooms->current_room+1);
                    player->x=2;
                    if (map->isPlatform(player->y, player->x)){
                        player->y--;
                    }
                }
            }
        }

        // Aggiorna lo schermo principale
        refresh();
        // Termina la modalità NCurses
        endwin();
    }
}
