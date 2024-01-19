
#include "collision.hpp"   
    
    // Funzione che verifica se una posizione (x, y) è occupata da un nemico nella lista
bool Base_isPositionOccupied(WINDOW* game, int x, int y, int direction) {
    char near_en;
    if(direction>0){
        near_en=mvwinch(game, y, x+1);
    }
    else if(direction<0){
        near_en=mvwinch(game, y, x-1);
    }

    if (near_en == 'X' || near_en=='Z' || near_en=='@') return true; //posizione occupata
    else return false; // La posizione è libera
}