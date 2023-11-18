#ifndef ENEMY_H
#define ENEMY_H


class Nemico
{
private:
    int x_;
    int y_;
public:
    Nemico(int x, int y);

    void draw(WINDOW *win);
    void cancella(WINDOW *win);
    void move(int playerX, int playerY);
    


};

#endif
