#ifndef ENEMY_H
#define ENEMY_H
#include "map/map.hpp"
#include "proiettile.hpp"
#include "personaggio.hpp"
#include <ncurses.h>
#include <iostream>
#include <ctime>

class Base_en;

struct lista_base_enemy{
    Base_en* b_en;
    lista_base_enemy* next;
};

typedef lista_base_enemy* p_base_en;

p_base_en e_head_insert(p_base_en& list,Base_en* enemy);
p_base_en e_tail_delete(p_base_en list, Map *map, p_pro p, Player* player);


class Base_en
{
protected:
    
public:
    
    int x_;
    int y_;
    
    
    Base_en(int x, int y, char type);
    int health;
    int counter_move;
    bool dead;
    int gold;
    int speed;
    char simbolo;
    int timer=3;
    int damage;
    void draw(WINDOW *win);
    bool enemyattack(int playerX, int playerY);
    void cancella(WINDOW *win);
    p_pro proiettili=NULL;
    void move(WINDOW* game,Map *map, char c);
    void sparareProiettile( int playerX, int playerY);
    static bool Base_isPositionOccupied(WINDOW* game, int x, int y, int direction);
};



#endif
