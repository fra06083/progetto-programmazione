
#include "collision.hpp"   
    
    // Funzione che verifica se una posizione (x, y) è occupata da un nemico nella lista
bool Base_isPositionOccupied(int x, int y, p_base_en base_en) {
    p_base_en currentEnemy_Base= base_en;
    while (currentEnemy_Base!=nullptr) {
        if (!currentEnemy_Base->b_en->dead && currentEnemy_Base->b_en->x_ == x && currentEnemy_Base->b_en->y_ == y) {
            return true; // La posizione è occupata da un nemico vivo
        }
       
        currentEnemy_Base = currentEnemy_Base->next;
    
    }
    return false; // La posizione è libera
}