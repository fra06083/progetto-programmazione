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
        if(counter_move==4){
        // Sposta il nemico verso il giocatore
        if (deltaX > 0)
        {
            x_++;
        }
        else if (deltaX < 0)
        {
            x_--;
            
        }
        counter_move=0;
        }
        counter_move=counter_move+1;
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
        //while (!map->platformUnder(x_, y_)){
        if(!map->platformUnder(x_, y_)){ 
            mvwaddch(game, y_, x_, ' '); // Cancellazione personaggio corrente
            y_ += 1;
            
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
p_en e_head_insert(p_en& list, Nemico *enemy1){
        p_en tmp=new lista_enemy;
        tmp->enemy= enemy1;
        tmp->next=list;
        list=tmp;
    
    return list;
}


p_en e_tail_delete(p_en list, Map *map, p_pro p) {
    p_en prevNode = NULL;
    p_en currentNode = list;
    p_pro colpito = p;

    while (colpito != NULL) {
        while (currentNode != NULL) {
            // Verifica se colpito e currentNode sono entrambi non NULL prima di confrontare le coordinate
            if (colpito->pro && currentNode->enemy && 
                (colpito->pro->x + 1 == currentNode->enemy->x_ || 
                 colpito->pro->x - 1 == currentNode->enemy->x_ || 
                 colpito->pro->x == currentNode->enemy->x_) && 
                colpito->pro->y == currentNode->enemy->y_) {

                colpito->pro->colpito=true;
                p_en nextNode = currentNode->next;
                delete currentNode->enemy;
                delete currentNode;

                if (prevNode != NULL) {
                    prevNode->next = nextNode;
                } else {
                    list = nextNode;
                }

                currentNode = nextNode;
            } else {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
        }

        // Reinizializza currentNode all'inizio del ciclo più esterno
        currentNode = list;
        colpito = colpito->next;
    }

    return list;
}





    
}
