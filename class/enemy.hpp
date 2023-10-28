#include <ncurses.h>
#ifndef ENEMY_H
#define ENEMY_H
#include "enemy.cpp"

class Nemico
{
public:
    Nemico(int x, int y) : x_(x), y_(y) {}

    void draw(WINDOW *win) const
    {
        mvwprintw(win, y_, x_, "X");
    }

    void move(int playerX, int playerY)
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

private:
    int x_;
    int y_;
};

#endif
