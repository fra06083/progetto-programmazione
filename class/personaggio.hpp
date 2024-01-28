#ifndef PERSONAGGIO_H // DA AGGIUSTARE, più che altro con game.run è il ciclo che fa andare avanti il gioco, i comandi li esegue layout utilizzando ncurses
#define PERSONAGGIO_H //
#define MAX_Y 24
#define MAX_X 80
#include <ncurses.h>
#include "map/map.hpp"
#include "objects.hpp"

class Player
{
public:
    //double jumpTime = 0.3;
    Map *map;
    int x, y, jump_max;
    int gravity;
    int Valuta, health=40, maxhp = 40, shield=0;
    int damage=1;
    bool isJumping, fall, isAlive;
     
    

    Player(int startX, int startY, int jump_max,Map *m, int health);
    void draw(WINDOW *g);
    void init();
    void p_move(WINDOW *g, char m);

    void set_stats(objects* obj);
    void set_shield();
    void heal();
};
#endif // PERSONAGGIO_HPP
