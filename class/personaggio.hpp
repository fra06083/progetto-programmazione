#ifndef PERSONAGGIO_H // DA AGGIUSTARE, più che altro con game.run è il ciclo che fa andare avanti il gioco, i comandi li esegue layout utilizzando ncurses
#define PERSONAGGIO_H //
#define MAX_Y 24
#define MAX_X 80
#include <ncurses.h>
#include "map.hpp"
#include "enemy.hpp"
#include "proiettile.hpp"
class Player
{
public:
    //double jumpTime = 0.3;
    Map *map;
    int x, y, jump_max;
    bool isAlive;
    int gravity;
    bool isJumping;
    int bodyHeight;
    int jumpHeight;

    Player(int startX, int startY, int jump_max,Map *m);
    void draw(WINDOW *g);
    void init();
    void p_move(WINDOW *g, char m);
    void checkCollision();
};
#endif // PERSONAGGIO_HPP
