#ifndef MEDIUM_ENEMY_H
#define MEDIUM_ENEMY_H
#include "map/map.hpp"
#include "proiettile.hpp"
#include "personaggio.hpp"
#include <ncurses.h>
#include <iostream>
#include <ctime>

class Medium_en;

struct lista_medium_enemy{
    Medium_en* m_en;
    lista_medium_enemy* next;
    };typedef lista_medium_enemy* p_medium_en;
    p_medium_en e_head_insert(p_medium_en& list,Medium_en* enemy);
p_medium_en e_tail_delete(p_medium_en list,  Map *map, p_pro proiettile,Player* player);



class Medium_en
{
protected:
    
public:
    
    int x_;
    int y_;
    
    
    Medium_en(int x, int y);
    int health=3;
    int counter_move=0;
    bool dead =false;
    void draw(WINDOW *win);
    void cancella(WINDOW *win);

    
    void move(WINDOW* game,Map *map,char c);
    
    
};




#endif