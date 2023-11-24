#include <ncurses.h>
#include <iostream>
#include <ctime>
#include "enemy.hpp"

    Nemico::Nemico(int x, int y) : x_(x), y_(y) {}

    void Nemico::draw(WINDOW *win)
    {
        mvwprintw(win, y_, x_, "X");
    }
    void Nemico::cancella(WINDOW *win)
    {
        mvwprintw(win, y_, x_, " ");
    }
    void Nemico::move(int playerX, int playerY)
    {
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

        if (deltaY > 0)
        {
            y_++;
        }
        else if (deltaY < 0)
        {
            y_--;
        }
        
    }


