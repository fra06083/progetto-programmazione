#include "game.hpp"
Game::Game(Layout *l, Map *m, Player *p)
{
    this->layout = l;
    this->map = m;
    this->player = p;
}
void Game::run()
{
    layout->init_screen();
    /* if (scelta == 1)
             {
                 ingame = true;
                 this->draw_box();
                 refresh();
                 // disegna solo il box, quando avremo la classe Game gestirà lui la partita
                 // layout si preoccupa solo di dare il template al gioco come se fossero
                 // due componenti diverse
             }
             else if (scelta == 2)
             {
             } // shop fuori gioco???
             else
                 refresh();
                 endwin();
         }
         */
        int scelta = layout->main_menu();
    if (scelta)
    {
        clear();
        if (scelta == 1){ // INIZIA PARTITA
            map->generateMap();
            player->init();
            bool game_over = false;
            while (!quit)
            { halfdelay(1);
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
            int ch = getch();
            if (ch == 'a' || ch == 'A' || ch == KEY_LEFT){
               player->p_move(layout->game, 'l');
            }
            if (ch == 'd' || ch == 'D' || ch == KEY_RIGHT) {
               player->p_move(layout->game, 'r');
            }
            if (ch == 'w' || ch == 'W' || ch == KEY_UP ){
               //quit = true;
                  
                player->jump(layout->game);              
       
                
            
                //player->isJumping=true;
               //player->updateJump();  refresh(); endwin();
            }
            if(ch=='e') {quit=true;}  
        }
        }
            refresh();
             endwin();
    }
}
