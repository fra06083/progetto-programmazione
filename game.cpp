#include "game.hpp"
Game::Game(Layout *l, Map *m, Player *p, Nemico *en, p_pro pr)
{
    this->layout = l;
    this->map = m;
    this->player = p;
    this->enemy = en;
    this->proiettile= pr;
        
    
}
int Game::updateJ(WINDOW* game, Player *p, Map *map, bool isJump, int i){

    if(i<=player->jump_max && !map->platformAbove(p->x, p->y)) {  // Interrompi il salto se c'è una piattaforma sopra. 
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
                enemy->move(player->x,player->y);
                enemy->draw(layout->game);
                wrefresh(layout->game);

                
                if (proiettile != NULL) {
                    p_pro count = proiettile;
                    while (count != NULL) {
                        if (count->pro->isAttivo()) {
                            count->pro->move(layout->game,proiettile);
                            //count->pro->draw(layout->game,player->x,player->y);
                        }
                        count = count->next;
                    }
                    proiettile = tail_delete(proiettile);
                }

                
                int ch = getch();
                if(ch==' '){

                    Proiettile *p= new Proiettile(player->x, player->y);
                    p->spara();
                    proiettile=head_insert(proiettile, p);
                    proiettile->pro->draw(layout->game, player->x, player->y);

                    wrefresh(layout->game);
                }
                if (ch == 'a' || ch == 'A' || ch == KEY_LEFT){
                    player->p_move(layout->game, 'l');
                }
                if (ch == 'd' || ch == 'D' || ch == KEY_RIGHT) {
                    player->p_move(layout->game, 'r');
                }
                if ((ch == 'w' || ch == 'W' || ch == KEY_UP)&& !player->isJumping){
                    
                    
                    player->isJumping=true;
                }
                if(ch=='e') {
                    quit=true;
                } 

                if(player->isJumping){
                this->counter=updateJ(layout->game, player,map, player->isJumping, this->counter);
                }
            }
        }
        refresh();
        endwin();
    }
}
