#ifndef ENEMY_H
#define ENEMY_H
#include "map.hpp"
#include "proiettile.hpp"
class Nemico
{
private:
    int x_;
    int y_;
public:
    Nemico(int x, int y);
    bool dead =false;
    void draw(WINDOW *win);
    void cancella(WINDOW *win);
    void move(WINDOW *game, Map *map, int playerX, int playerY);
    void death(WINDOW* game, Map *map, p_pro proiettile);


};

#endif
