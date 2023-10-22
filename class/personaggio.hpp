#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H

#include "Map.hpp"
#include <ncurses.h>
/*
class Player {
public:
    int x, y;
    bool isAlive;
    int gravity;
    int jumpHeight;
    bool isJumping;   
    int bodyHeight;


    Player(int startX, int startY) : x(startX), y(startY),jumpHeight(4), isAlive(true), isJumping(false), gravity(1), bodyHeight(4) {}


    void init(Map& map) {
        // Trova la piattaforma più in basso nella mappa
        int lowestY = 0;
        for (int i = 0; i < MAX_X; i++) {
            for (int j = 0; j < MAX_Y; j++) {
                if (map.isPlatform(i, j) && j > lowestY) {
                    lowestY = j;
                }
            }
        }
        y = lowestY-2; //- bodyHeight; // Posiziona il baricentro dello stickman sotto le gambe, sopra la piattaforma più bassa trovata
    }




    void draw(WINDOW* win) {
    
        mvwprintw(win, y, x,"@");  // Testa
        mvwprintw(win, y +1, x, "|"); // Corpo
        mvwprintw(win, y +1, x - 1, "/");  // Braccio sinistro
        mvwprintw(win, y +1, x + 1, "\\");  // Braccio destro
        mvwprintw(win, y+2, x - 1, "/");  // Gamba sinistra
        mvwprintw(win, y+2, x + 1, "\\");  // Gamba destra
    }

    void move_right(int dx, int dy, Map map, WINDOW* win) {
        mvwaddch(win, y, x, ' ');  // Cancellazione personaggio corrente
        x += dx;
        draw(win);  // Disegno del personaggio nella nuova posizione

        if (map.isPlatform(x, y + dy)) {
            y += dy;
        }

        // Controllo se il giocatore è caduto dalla mappa
        if (y >= MAX_Y) {
            isAlive = false;
        }
    }

    void move_left(int dx, int dy, Map map, WINDOW* win) {
        mvwaddch(win, y, x, ' ');  // Cancellazione personaggio corrente
        x -= dx;
        draw(win);  // Disegno del personaggio nella nuova posizione

        if (map.isPlatform(x, y + dy)) {
            y += dy;
        }

        // Controllo se il giocatore è caduto dalla mappa
        if (y >= MAX_Y) {
            isAlive = false;
        }
    }

    void jump(Map& map, WINDOW* win) {
        if (!map.isPlatform(x, y - 1)) {
            mvwaddch(win, y, x, ' ');  // Cancellazione personaggio corrente
            y -= 3;
            draw(win);  // Disegno del personaggio nella nuova posizione
        }
    }


   /*void updateJump(Map& map) {
        if (isJumping) {
            if (jumpHeight > 0) {
                if (!map.isPlatform(x, y - 1)) {
                    y -= 1;
                    jumpHeight--;
                } else {
                    jumpHeight = 0;
                }
            } else if (jumpHeight == 0) {
                if (!map.isPlatform(x, y + 1)) {
                    jumpHeight--;
                } else {
                    jumpHeight = -4;
                }
            } else if (jumpHeight < 0 && jumpHeight >= -4) {
                if (!map.isPlatform(x, y + 1)) {
                    y += 1;
                    jumpHeight--;
                } else {
                    jumpHeight = 0;
                }
            } else {
                isJumping = false;
            }
        } else {
            if (!map.isPlatform(x, y + 1)) {
                y += gravity;
            }
        }

        // Controlla se il giocatore è caduto dalla mappa
        if (y >= MAX_Y) {
            isAlive = false;
        }
    }
void updateJump(Map& map) {
    if (isJumping) {
        if (jumpHeight > 0) {
            if (!map.isPlatform(x, y - 1)) {
                y--;
                jumpHeight--;
            } else {
                jumpHeight = 0;
            }
        } else if (jumpHeight == 0) {
            if (!map.isPlatform(x, y + bodyHeight + 1)) {
                jumpHeight--;
            } else {
                jumpHeight = -4;
            }
        } else if (jumpHeight < 0 && jumpHeight >= -4) {
            if (!map.isPlatform(x, y + bodyHeight + 1)) {
                y++;
                jumpHeight++;
            } else {
                jumpHeight = 0;
            }
        } else {
            isJumping = false;
        }
    } else {
        if (!map.isPlatform(x, y + bodyHeight + 1)) {
            y += gravity;
        }
    }

    // Controlla se il giocatore è caduto dalla mappa
    if (y + bodyHeight >= MAX_Y) {
        isAlive = false;
    }
}
*/
/*
void updateJump(Map& map) {
    // If the player is jumping
    if (isJumping) {
        // Move the player up
        y--;

        // Check if the player has hit a platform
        if (map.isPlatform(x, y)) {
            // Stop the player from jumping
            isJumping = false;
        }
    } else {
        // Check if the player is standing on a platform
        if (!map.isPlatform(x, y + bodyHeight + 1)) {
            // Move the player down
            y++;
        }
    }

    // Check if the player has fallen off the map
    if (y + bodyHeight >= MAX_Y) {
        isAlive = false;
    }
}

    
    void checkCollision(Map& map) {
        if (map.isPlatform(x, y + bodyHeight)) {
            isJumping = false;
            jumpHeight = 0;
        }
    }
};
*/
#include "Map.hpp"
#include <ncurses.h>

class Player {
public:
    double jumpTime=0.3;
    int x, y;
    bool isAlive;
    int gravity;
    bool isJumping;   
    int bodyHeight;
    int jumpHeight;


    Player(int startX, int startY) : x(startX), y(startY),jumpHeight(4), isAlive(true), isJumping(false), gravity(1), bodyHeight(4) {}


    void init(Map& map) {
        // Trova la piattaforma più in basso nella mappa
        int lowestY = 0;
        for (int i = 0; i < MAX_X; i++) {
            for (int j = 0; j < MAX_Y; j++) {
                if (map.isPlatform(i, j) && j > lowestY) {
                    lowestY = j;
                }
            }
        }
        x=1;
        y = lowestY-bodyHeight; //- bodyHeight; // Posiziona il baricentro dello stickman sotto le gambe, sopra la piattaforma più bassa trovata
    }




    void draw(WINDOW* win) {
    
        mvwprintw(win, y, x,"@");  // Testa
        mvwprintw(win, y +1, x, "|"); // Corpo
        mvwprintw(win, y +1, x - 1, "/");  // Braccio sinistro
        mvwprintw(win, y +1, x + 1, "\\");  // Braccio destro
        mvwprintw(win, y+2, x -1, "/");  // Gamba sinistra
        mvwprintw(win, y+2, x + 1, "\\");  // Gamba destra
    }
    void p_move (Map map, WINDOW* win) {
        int oldx = x;
        int oldy = y;
        int ch = wgetch(win); 
                    switch (ch) {
                        case KEY_UP:
                          // Salva la posizione corrente del cursore

                        // Itera attraverso le posizioni intermedie
                        /*for (int i = 0; i < 5; i++) {
                             // Sposta il cursore alla posizione desiderata
                            y=y-1;
                            move(x,y);
                            

                             // Stampa il carattere
                            //draw(win);

                            // Attendi un breve intervallo di tempo
                            napms(100);
                        }
                        for (int i = 0; i < 5; i++) {
                        // Sposta il cursore alla posizione desiderata
                            y=y+1;
                            move(x,y);
                            

                             // Stampa il carattere
                            //draw(win);

                            // Attendi un breve intervallo di tempo
                            napms(100);
                        }

  // Ripristina la posizione del cursore
                         move(oldx, oldy);*/
                         isJumping = true;
                            break;
                        case KEY_LEFT:
                            mvwaddch(win, y, x, ' ');  // Cancellazione personaggio corrente
                            x -= 1;
                            draw(win);  // Disegno del personaggio nella nuova posizione

                            // Controllo se il giocatore è caduto dalla mappa
                            if (x < 0) {
                            isAlive = false;
                            }
                            break;
                        case KEY_RIGHT:
                            mvwaddch(win, y, x, ' ');  // Cancellazione personaggio corrente
                            x += 1;
                            draw(win);  // Disegno del personaggio nella nuova posizione

                            // Controllo se il giocatore è caduto dalla mappa
                            if (x >= MAX_X) {
                            isAlive = false;
                            }
                            break;
                    }
    }
    /*
    void move_right(int dx, int dy, Map map, WINDOW* win) {
        mvwaddch(win, y, x, ' ');  // Cancellazione personaggio corrente
        x += dx;
        draw(win);  // Disegno del personaggio nella nuova posizione

        if (map.isPlatform(x, y + dy)) {
            y += dy;
        }

        // Controllo se il giocatore è caduto dalla mappa
        if (y >= MAX_Y) {
            isAlive = false;
        }
    }

    void move_left(int dx, int dy, Map map, WINDOW* win) {
        mvwaddch(win, y, x, ' ');  // Cancellazione personaggio corrente
        x -= dx;
        draw(win);  // Disegno del personaggio nella nuova posizione

        if (map.isPlatform(x, y + dy)) {
            y += dy;
        }

        // Controllo se il giocatore è caduto dalla mappa
        if (y >= MAX_Y) {
            isAlive = false;
        }
    }
    */
    void jump(Map& map, WINDOW* win) {
        if (!map.isPlatform(x, y - 1)) {
            mvwaddch(win, y, x, ' ');  // Cancellazione personaggio corrente
            y -= 3;
            draw(win);  // Disegno del personaggio nella nuova posizione
        }
    }

/*
   void updateJump(Map& map) {
       // If the player is jumping
        if (isJumping) {
            // Move the player up
            y--;

            // Check if the player has hit a platform
            if (map.isPlatform(x, y)) {
                // Stop the player from jumping
                isJumping = false;
            }
        } else {
            // Check if the player is standing on a platform
            if (!map.isPlatform(x, y + bodyHeight + 1)) {
                // Move the player down
                y++;
            }
        }

        // Check if the player has fallen off the map
        if (y + bodyHeight >= MAX_Y) {
            isAlive = false;
        }
    }
*/void updateJump(Map& map) {
    // If the player is jumping
    if (isJumping) {
        // Move the player up
        int i=0;
        while(i<=jumpHeight){
            y--;

            i=i+1;
            // Check if the player has hit a platform
        if (map.isPlatform(x, y)) {
            // Stop the player from jumping
                isJumping = false;
            }
        }   
        isJumping = false;
      
                
        
    } else {
        // Move the player down
    

        // Check if the player has fallen off the map
        if (y + bodyHeight >= MAX_Y) {
            isAlive = false;
        }
    }
}

    
    void checkCollision(Map& map) {
        if (map.isPlatform(x, y + bodyHeight)) {
            isJumping = false;
            jumpHeight = 0;
        }
    }
};

#endif// PERSONAGGIO_HPP
