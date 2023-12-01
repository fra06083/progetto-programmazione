
#include "game.hpp"
Game::Game(Layout *l, Map *m, Player *p, Nemico *en, p_pro pr)
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
    layout->init_screen();
    int scelta = layout->main_menu();
    if (scelta)
    {
        clear();
        if (scelta == 1){ // INIZIA PARTITA
            map->generateMap();
            player->init();
            bool game_over = false;
            char p_direction='r'; //inizializzazione direzione proiettile
            while (!quit){
                halfdelay(1);
                
                clear();
                // Draw map
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
                layout->draw_box();
                player->draw(layout->game);
                enemy->move(layout->game,map,player->x,player->y);
                enemy->draw(layout->game);
                wrefresh(layout->game);

                
                if (proiettile != NULL) {
                    p_pro count = proiettile;
                    while (count != NULL) {
                        if (count->pro->isAttivo()) {
                            count->pro->move(layout->game,proiettile,count->pro->dir);
                            //count->pro->draw(layout->game,player->x,player->y);
                        }
                        count = count->next;
                    }
                    proiettile = tail_delete(proiettile, map);
                }
                enemy->death(layout->game,map,proiettile);
                
                int ch = getch();
                if(ch==' '){

                    Proiettile *p= new Proiettile(player->x, player->y);
                    p->spara();
                    p->dir=p_direction;
                    proiettile=head_insert(proiettile, p);
                    proiettile->pro->draw(layout->game, player->x, player->y);

                    wrefresh(layout->game);
                }
                if (ch == 'a' || ch == 'A' || ch == KEY_LEFT){
                    player->p_move(layout->game, 'l');
                    p_direction='l';
                }
                if (ch == 'd' || ch == 'D' || ch == KEY_RIGHT) {
                    player->p_move(layout->game, 'r');
                    p_direction='r';
                }
                if ((ch == 'w' || ch == 'W' || ch == KEY_UP) && (!player->fall && !player->isJumping)){
                    
                    
                    player->isJumping = true;
                }
                if(ch=='e') {
                    quit=true; 
                } 
               if (map->platformUnder(player->x, player->y)) player->fall = false;
               if (!player->isJumping && !map->platformUnder(player->x, player->y)){
                  player->fall = true;
                  player->y++;
               }
                if(player->isJumping && !player->fall){
                this->counter=updateJump(layout->game, player,map, player->isJumping, this->counter);
                }
            }
        }
        refresh();
        endwin();
    }
}
