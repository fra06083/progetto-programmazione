#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H

#include "personaggio.cpp"

#include "Map.hpp"
#include <ncurses.h>
#include <iostream>
#include <ctime>

class Player {
public:
    int x, y;
    int jumpHeight;
    bool isJumping;
    bool isAlive;
    int gravity;

    Player(int startX, int startY) : x(startX), y(startY), jumpHeight(0), isJumping(false), isAlive(true), gravity(1){}
    
    
    void init(Map map) {
        //trova la piattaforma più in basso nella mappa
        int lowestY = 0;
        for (int i = 0; i < MAX_X; i++) {
            for (int j = 0; j < MAX_Y; j++) {
                if (map.isPlatform(i, j)) {
                    if(lowestY>=j){
                    lowestY =lowestY;
                    }
                    else{lowestY=j;
                    }
                }
               
            }
        }
        }

    void move_right(int dx, int dy, Map map, WINDOW* win) {
        
        
        if (x< MAX_X- 1){
        mvwaddch(win, y,x + dx, ' ');
        x++;
        mvwaddch(win, y,x + dx, '@');
        }
        if (map.isPlatform(x+ dx, y)) {
        // la nuova posizione è su una piattaforma
        x = x+dx;
        y = x+dy;
        } else if (map.isPlatform(x+dx, y)) {
        // la nuova posizione è su una piattaforma orizontalmente adiacente alla psizione corrente
        x = x+dx;
        } else if (map.isPlatform(x,y+dy)) {
        //la nuova posizione è su una piattaforma verticalmente adiacente alla psizione corrente
        y = y+dy;
        } else {
        // la nuova posizione è una piattaforma
        return;
        
        }

        // ontrolla se player è caduto dalla mappa
        if (y >= MAX_Y) {
        bool isAlive = false;
        
        }wrefresh(win);
    }

    
    void move_left(int dx, int dy, Map map, WINDOW* win) {
    int newX= x+dx;
    int newY= y+dy;
    // Muovi il personaggio verso sinistra
    if(x > 0){
        mvwaddch(win, y, x+ dx, ' ');
        x--;
        mvwaddch(win, y, x+ dx, '@');
        }
    if (map.isPlatform(newX, y+dy)) {
        //  la nuova posizione è su una piattaforma
        x = x+dx;
        y = y+dy;
    } else if (map.isPlatform(x+dx, y)) {
        // la nuova posizione è su una piattaforma orizontalmente adiacente alla psizione corrente
        x = x+dx;
    } else if (map.isPlatform(x, y+dy)) {
        // la nuova posizione è su una piattaforma verticalmente adiacente alla psizione corrente
        y = y+dy;
    } else {
        // la nuova posizione è una piattaforma
        return;
    }

    // controlla se player è caduto dalla mappa
    if (y >= MAX_Y) {
        bool isAlive = false;
    }wrefresh(win);
    }


    void jump() {
        if (!isJumping) {
            isJumping = true;
            jumpHeight = 4;
        }
    }

  
 void updateJump(Map& map) {
        if (isJumping) {
            if (jumpHeight > 0) {
                if (!map.isPlatform(x, y - jumpHeight)) {
                    y -= jumpHeight;
                    jumpHeight--;
                } else {
                    jumpHeight = 0;
                }
            } else if (jumpHeight == 0) {
                if (!map.isPlatform(x, y - jumpHeight)) {
                    jumpHeight--;
                } else {
                    jumpHeight = -4;
                }
            } else if (jumpHeight < 0 && jumpHeight >= -4) {
                if (!map.isPlatform(x, y - jumpHeight)) {
                    y += abs(jumpHeight);
                    jumpHeight--;
                } else {
                    jumpHeight = 0;
                }
            } else {
                isJumping = false;
            }
        }else {
            if (!map.isPlatform(x, y + 1)) {
                y += gravity;
                }
        }
        // controlla se player è caduto dalla mappa
        if (y >= MAX_Y) {
            isAlive = false;
        }
    }


   void checkCollision(Map map) {
        if (map.isPlatform(x, y + 1)) {
            isJumping = false;
        }
    } 


};

#endif // PERSONAGGIO_HPP
