#include <ncurses.h>
#include <iostream>
#include <ctime>
#include "enemy.hpp"

    Nemico::Nemico(int x, int y) : x_(x), y_(y) {}

    void Nemico::draw(WINDOW *win)
    { if(!dead){
        mvwprintw(win, y_, x_, "X");
    }
    }
    void Nemico::cancella(WINDOW *win)
    {
        mvwprintw(win, y_, x_, " ");
    }
    void Nemico::move(WINDOW* game,Map *map, int playerX, int playerY)
    { 
        if(!dead){
        // Calcola la direzione verso il giocatore
        int deltaX = playerX - x_;
        int deltaY = playerY - y_;

        // Sposta il nemico verso il giocatore
        if (deltaX > 0)
        {
            x_++;
        }
        else if (deltaX < 0)
        {
            x_--;
        }
        
        /*
        if (deltaY > 0)
        {
            y_++;
        }
        else if (deltaY < 0)
        {
            y_--;
        }
        */
        while (!map->platformUnder(x_, y_)){
        mvwaddch(game, y_, x_, ' '); // Cancellazione personaggio corrente
        y_ += 1;
        napms(50);
        draw(game);
    }
  }
}

void Nemico::death(WINDOW* game, Map *map, p_pro proiettile) {
    if (proiettile != NULL) {
        p_pro count = proiettile;
        while (count != NULL) {
            if(count->pro->x+1==x_ && count->pro->y==y_){
               cancella(game);
               dead=true;  
            }
            count = count->next;
        }
      
    }

    
}
