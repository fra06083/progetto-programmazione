#ifndef TOUGH_ENEMY_H
#define TOUGH_ENEMY_H
#include "map/map.hpp"
#include "proiettile.hpp"
#include "personaggio.hpp"
#include <ncurses.h>
#include <iostream>
#include <ctime>


class Tough_en;
struct lista_tough_enemy{
    Tough_en* t_en;
    lista_tough_enemy* next;
};
typedef lista_tough_enemy* p_tough_en;
p_tough_en e_head_insert(p_tough_en& list,Tough_en* enemy);
p_tough_en e_tail_delete(p_tough_en list,  Map *map, p_pro proiettile,Player* player);


class Tough_en
{
protected:
    
public:
    
    int x_;
    int y_;
    
    
    Tough_en(int x, int y);
    int health=7;
    int counter_move=0;
    bool dead =false;
    void draw(WINDOW *win);
    void cancella(WINDOW *win);
    void move(WINDOW* game,Map *map, char c);
    int points=10;
    
};



#endif