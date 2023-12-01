#ifndef ENEMY_H
#define ENEMY_H


class Nemico
{
public:
    
    int x, y, countdown, time;
    bool defeat;
    Nemico(int x, int y, int time);

    void draw(WINDOW *win);
    void cancella(WINDOW *win);
    void move(int playerX, int playerY);
    


};

#endif
