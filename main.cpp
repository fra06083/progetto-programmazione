#include "class/personaggio.hpp"
#include "class/map.hpp"
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
    refresh();
    wrefresh(win);
    keypad(win, true);
    curs_set(0);
}
int main(int argc, char **argv) {
    init_game();
    char menu[3][20] = {"Nuova Partita", "Shop", "Esci dal Gioco"};
    bool exit=false;
    int ch;
    int scelta = 0;    
    
    while (!exit){
         for (int i = 0; i<3;i++){
            if (scelta==i) wattron(win, A_REVERSE);
                mvwprintw(win, 2*(i+1), 2, "%s", menu[i]);
                wattroff(win, A_REVERSE);
        }
          box(win, 0, 0);
          ch = wgetch(win);
        switch (ch) {
            
            case KEY_UP:
                if (scelta>0){
                  scelta--;
                } else {
                    scelta = 2;
                }
                break;
            case KEY_DOWN:
                if (scelta<2){
                  scelta++;
                } else {
                    scelta = 0;
                }
                break;
        }
       
        if (ch == 10) {
            if (scelta == 2) exit = true;
            if (scelta==0){
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
                        player.move_left(1, 0, map, win);
                        break;
                    case KEY_RIGHT:
                        player.move_right(1, 0, map, win);
                        break;
                }

                // Update player jump
                player.updateJump(map);
                //player.checkCollision();
                
                // Check collision
                if (!player.isAlive) {
                    wclear(win);
                    mvprintw(MAX_Y / 2, MAX_X/ 2, "Game Over!");
                    timeout(1000);
                    wrefresh(win);
                    wgetch(win);
                    break;
                }
            }
        }
        }nodelay(win, false);
            wclear(win);
    }

    endwin();
    return 0;
}
