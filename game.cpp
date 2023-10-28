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
            {
                clear();
                // Draw map
                for (int i = 2; i < MAX_X; i++)
                {
                    for (int j = 2; j < MAX_Y; j++)
                    {
                        if (map->isPlatform(i, j))
                        {
                            move(j, i);
                            addch('=');
                        }
                    }
                }
                 layout->draw_box();
                 player->draw();
            int s = getch();
            if (s) {
                refresh(); endwin();
          //  }
        }
        }
        }
            refresh();
             endwin();
    }
}