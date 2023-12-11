#ifndef ENEMY_H
#define ENEMY_H
#include "map/map.hpp"
#include "proiettile.hpp"
class Nemico
{
protected:
    
public:
    int x_;
    int y_; 
    Nemico(int x, int y);
    int counter_move=0;
    bool dead =false;
    void draw(WINDOW *win);
    void cancella(WINDOW *win);
    void move(WINDOW *game, Map *map, int playerX, int playerY);
    void death(WINDOW* game, Map *map, p_pro proiettile);


};
struct lista_enemy{
    Nemico* enemy;
    lista_enemy* next;
 };
typedef lista_enemy* p_en;
p_en e_head_insert(p_en& list,Nemico* enemy);
p_en e_tail_delete(p_en list,  Map *map, p_pro proiettile);

#endif
