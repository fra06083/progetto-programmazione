#ifndef PERSONAGGIO_H // DA AGGIUSTARE, più che altro con game.run è il ciclo che fa andare avanti il gioco, i comandi li esegue layout utilizzando ncurses
#define PERSONAGGIO_H //
#define MAX_Y 24
#define MAX_X 80
#include <ncurses.h>
#include "map.hpp"
class Player
{
public:
    double jumpTime = 0.3;
    Map *map;
    int x, y;
    bool isAlive;
    int gravity;
    bool isJumping;
    int bodyHeight;
    int jumpHeight;

    Player(int startX, int startY, Map *m);
    void draw(WINDOW *g);
    void init();
    void p_move(WINDOW *g, char m);
    void jump(WINDOW *game);
    void jump_right(WINDOW *g);
    void jump_left(WINDOW *game);
    void updateJump();
    void checkCollision();

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
    */
};
#endif // PERSONAGGIO_HPP
