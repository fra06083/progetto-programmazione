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
    int oldx = x;
    int oldy = y;

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
void Player::jump(WINDOW *game) {
    this->isJumping = true;
    int i = 1;

    while (i <= this->jump_max) {
        
        if (map->platformAbove(x, y)) {
            break;  // Interrompi il salto se c'è una piattaforma sopra.
        } else {
            y = y - 1;
            i++;
        }

        mvwaddch(game, y + 1, x, ' ');
        wrefresh(game);
        napms(50);
        mvwaddch(game, y, x, '@');
        wrefresh(game);

        // Effettua un passo laterale durante il salto se viene premuto un tasto.
        
        int ch = getch();
        if (ch == 'a' || ch == 'A' || ch == KEY_LEFT) {
            if (!map->isPlatform(x - 1, y))
                this->p_move(game, 'l');
        } else if (ch == 'd' || ch == 'D' || ch == KEY_RIGHT) {
            if (!map->isPlatform(x + 1, y))
                this->p_move(game, 'r');
        }
    }

    // Ripristina la posizione iniziale del personaggio dopo il salto.
    while (i != 1) {
        if (map->platformUnder(x, y)) {
            break;  // Interrompi la discesa se c'è una piattaforma sotto.
        } else {
            y = y + 1;
            i--;
        }

        mvwaddch(game, y - 1, x, ' ');
        wrefresh(game);
        napms(50);
        mvwaddch(game, y, x, '@');
        wrefresh(game);

        int ch = getch();
        if (ch == 'a' || ch == 'A' || ch == KEY_LEFT) {
            if (!map->isPlatform(x - 1, y))
                this->p_move(game, 'l');
        } else if (ch == 'd' || ch == 'D' || ch == KEY_RIGHT) {
            if (!map->isPlatform(x + 1, y))
                this->p_move(game, 'r');
        }
    }

    // Fine del salto, reimposta 'isJumping' a false.
    this->isJumping = false;
}



        
       

void Player::updateJump()
{
    // If the player is jumping
    if (isJumping)
    {
        // Move the player up
        int i = 1;
        while (i <= jumpHeight)
        {
            y--;

            i = i + 1;
            // Check if the player has hit a platform
            if (map->isPlatform(x, y))
            {
                // Stop the player from jumping
                isJumping = false;
            }
        }
        napms(500);
        while (i >=1)
        {
            y++;

            i = i - 1;
            // Check if the player has hit a platform
            if (map->isPlatform(x, y))
            {
                // Stop the player from jumping
                isJumping = false;
            }
        }
        isJumping = false;
    }
    else
    {
        // Move the player down

        // Check if the player has fallen off the map
        if (y + bodyHeight >= MAX_Y)
        {
            isAlive = false;
        }
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
}
