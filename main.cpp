#include "personaggio.hpp"
#include "Map.hpp"
#include <ncurses.h>
#include <iostream>
#include <ctime>


WINDOW *win;

void init_game() {
    initscr();
    noecho();
    
    win = newwin(MAX_Y, MAX_X, 0, 0);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    keypad(win, true);
    curs_set(0);
}

int main(int argc, char **argv) {
    init_game();

    wclear(win);
    mvwprintw(win, 2, 2, "Nuova Partita");
    mvwprintw(win, 4, 2, "Shop");
    mvwprintw(win, 6, 2, "Esci dal Gioco");
    wrefresh(win);
    bool exit=false;
    char ch;
        
    ch = wgetch(win);
    while (!exit){
        wclear(win);

        switch (ch) {
            case 'n':
                wattron(win, A_STANDOUT);
                mvwprintw(win, 2, 2, "Nuova Partita");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, 4, 2, "Shop");
                mvwprintw(win, 6, 2, "Esci dal Gioco");
                wrefresh(win);
                break;
            case 's':
                wattron(win, A_STANDOUT);
                mvwprintw(win, 4, 2, "Shop");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, 2, 2, "Nuova Partita");
                mvwprintw(win, 6, 2, "Esci dal Gioco");
                wrefresh(win);
                break;
            case 'e':
                wattron(win, A_STANDOUT);
                mvwprintw(win, 6, 2, "Esci dal Gioco");
                wattroff(win, A_STANDOUT);
                mvwprintw(win, 2, 2, "Nuova Partita");
                mvwprintw(win, 4, 2, "Shop");
                wrefresh(win);
                break;
            case 'q':
                exit=true;
                break;
            default:
                mvwprintw(win, 2, 2, "Nuova Partita");
                mvwprintw(win, 4, 2, "Shop");
                mvwprintw(win, 6, 2, "Esci dal Gioco");
                wrefresh(win);
                break;
        }
        
        if (ch == 'n') {
            wclear(win);
            srand(time(0));
            keypad(win, TRUE);
            timeout(100);

            Map map;
            Player player(MAX_X / 2,MAX_Y / 2);
            player.init(map);

            bool game_over = false;
            
           
                wrefresh(win);
                //nodelay(win, true);
            while (!game_over) {
                clear();
                 // Draw map
            for (int i = 0; i < MAX_X; i++) {
                    for (int j = 0; j < MAX_Y; j++) {
                        if (map.isPlatform(i, j)) {
                            move(j, i);
                            addch('=');
                        }
                    }
                }
                 // Check if player is jumping
                if (player.isJumping) {
                // Update player jump
                player.updateJump(map);}



                // Draw player
                
                if (player.isJumping) {
                    if (player.jumpHeight > 0) {
                        mvprintw(player.y, player.x, " @ ");
                    } else if (player.jumpHeight == 0) {
                        mvprintw(player.y, player.x, " @ ");
                    } else if (player.jumpHeight < 0 && player.jumpHeight >= -10) {
                        mvprintw(player.y, player.x, " @ ");
                    } else {
                        mvprintw(player.y, player.x, " @ ");
                    }
                } else {
                    mvprintw(player.y, player.x, "@");
                }
                                                       
               refresh(); 

                int ch = wgetch(win);
                switch (ch) {
                    case KEY_UP:
                        player.jump();
                        player.isJumping=true;
                        break;
                    case KEY_LEFT:
                        player.move_left(-1, 0, map, win);
                        break;
                    case KEY_RIGHT:
                        player.move_right(1, 0, map, win);
                        break;
                    case 'q':
                        game_over = true;
                        break;
                }

                // Update player jump
                player.updateJump(map);
                //player.checkCollision();
                
                // Check collision
                if (!player.isAlive) {
                    wclear(win);
                    mvprintw(MAX_Y / 2, MAX_X/ 2, "Game Over!");
                    wrefresh(win);
                    wgetch(win);
                    break;
                }
            }
        }nodelay(win, false);
            wclear(win);
    }

    endwin();
    return 0;
}
