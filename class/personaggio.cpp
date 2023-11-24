#include <ncurses.h>
#include <iostream>
#include <ctime>
#include "personaggio.hpp"
Player::Player(int startX, int startY,int jump_m, Map *m) : x(startX),jump_max(jump_m), y(startY), map(m), jumpHeight(7), isAlive(true), isJumping(false), gravity(1), bodyHeight(1){}
void Player::draw(WINDOW *game)
{
    mvwprintw(game, y, x, "@");
    wrefresh(game);
}
void Player::init()
{
    // Trova la piattaforma più in basso nella mappa
    int lowestY = 0;
    for (int i = 2; i < MAX_X; i++)
    {
        for (int j = 2; j < MAX_Y; j++)
        {
            if (map->isPlatform(i, j) && j > lowestY)
            {
                lowestY = j;
            }
        }
    }
    x = 1;
    y = MAX_Y-2; //- bodyHeight; // Posiziona il baricentro dello stickman sotto le gambe, sopra la piattaforma più bassa trovata
}
void Player::p_move(WINDOW *game, char m = 'r')
{
    
        // Salva la posizione corrente del cursore

        // Itera attraverso le posizioni intermedie
        /*for (int i = 0; i < 5; i++) {
             // Sposta il cursore alla posizione desiderata
            y=y-1;
            move(x,y);


             // Stampa il carattere
            //draw(win);

            // Attendi un breve intervallo di tempo
            napms(100);
        }
        for (int i = 0; i < 5; i++) {
        // Sposta il cursore alla posizione desiderata
            y=y+1;
            move(x,y);


             // Stampa il carattere
            //draw(win);

            // Attendi un breve intervallo di tempo
            napms(100);
        }

// Ripristina la posizione del cursore
         move(oldx, oldy);*/
     //   isJumping = true;
   if (m == 'l' && x > 1){
        mvwaddch(game, y, x, ' '); // Cancellazione personaggio corrente
        x -= 1;
        draw(game); // Disegno del personaggio nella nuova posizione
   }
        // Controllo se il giocatore è caduto dalla mappa
        if (x < 0)
        {
            isAlive = false;
        }
    if (m == 'r' && x<MAX_X-1){
        mvwaddch(game, y, x, ' '); // Cancellazione personaggio corrente
        x += 1;
        draw(game); // Disegno del personaggio nella nuova posizione
     
    }
    while (!map->platformUnder(x, y) && !this->isJumping){
      mvwaddch(game, y, x, ' '); // Cancellazione personaggio corrente
        y += 1;
        napms(50);
        draw(game);
    }
}

void Player::checkCollision()
{
    if (map->isPlatform(x, y + bodyHeight))
    {
        isJumping = false;
        jumpHeight = 0;
    }
}