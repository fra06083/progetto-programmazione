#ifndef PROIETTILE_H 
#define PROIETTILE_H
#include <iostream>
#include <ncurses.h>
 struct lista_proiettili;
class Proiettile {
public:
    int x, y;
    bool sparato = false;
    Proiettile(int startX, int startY);
    void spara();
    void move(WINDOW* game, lista_proiettili *proiettile);
    bool haColpitoPlayer(int playerX, int playerY);
    bool haRaggiuntoFineSchermo(int screenWidth);
    void draw(WINDOW *game, int playerX, int playerY);
    bool isAttivo();

};

struct lista_proiettili{
    Proiettile *pro;
    lista_proiettili* next;
 };
typedef lista_proiettili* p_pro;
p_pro head_insert(p_pro& list, Proiettile* pr);
p_pro tail_delete(p_pro list);

#endif //PROIETTILE_HPP