#include <ncurses.h>
#include <iostream>
#include <ctime>
#include "enemy.hpp"

    Nemico::Nemico(int x, int y, int time) : x(x), y(y), time(time) {
        this->countdown = time;
    }

    void Nemico::draw(WINDOW *win)
    {
        mvwprintw(win, y, x, "X");
    }
    void Nemico::cancella(WINDOW *win)
    {
        mvwprintw(win, y, x, " ");
    }
    void Nemico::move(int playerX, int playerY)
    {
        // Calcola la direzione verso il giocatore
        int deltaX = playerX - x;
        int deltaY = playerY - y;

        // Sposta il nemico verso il giocatore
        if (deltaX > 0)
        {
            x++;
        }
        else if (deltaX < 0)
        {
            x--;
        }

        if (deltaY > 0)
        {
            y++;
        }
        else if (deltaY < 0)
        {
            y--;
        }
        
    }


