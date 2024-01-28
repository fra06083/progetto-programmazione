#include <ncurses.h>
#include <iostream>
#include <ctime>
#include "personaggio.hpp" // health prenderà dal file di salvataggio il dato se non esiste, mette 100
Player::Player(int startX, int startY,int jump_m, Map *m, int h) : health(h), x(startX),jump_max(jump_m), y(startY), map(m), isAlive(true), isJumping(false), gravity(1){}
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
    x=MAX_X/2;
    y = MAX_Y-2; //- bodyHeight; // Posiziona il baricentro dello stickman sotto le gambe, sopra la piattaforma più bassa trovata
}
void Player::p_move(WINDOW *game, char m = 'r')
{
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

    //Quando si acquista qualcosa si aggiornano le stats in base ai potenziamenti in possesso
void Player::set_stats(objects* obj){
    this->maxhp = 40 + (5*obj->get_possession(5)) + (7*obj->get_possession(6)) + (10*obj->get_possession(7));
    this->damage= 1 + (1*obj->get_possession(2)) + (2*obj->get_possession(3)) + (3*obj->get_possession(4));
}

//Imposta uno scudo pari a metà degli hp massimi
void Player::set_shield(){
    this->shield=this->maxhp/2;
}

//Cura di 1/3 degli hp massimi
void Player::heal(){
    float HPregen=maxhp/3;
    health=health + HPregen;
    if(this->health>this->maxhp) health=this->maxhp;
}
