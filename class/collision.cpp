
#include "collision.hpp"   
    
    // Funzione che verifica se una posizione (x, y) è occupata da un nemico nella lista
bool Base_isPositionOccupied(int x, int y, p_base_en base_en) {
    p_base_en currentEnemy_Base= base_en;
    while (currentEnemy_Base!=NULL) {
        if (!currentEnemy_Base->b_en->dead && currentEnemy_Base->b_en->x_ == x && currentEnemy_Base->b_en->y_ == y) {
            return true; // La posizione è occupata da un nemico vivo
        }
       
        currentEnemy_Base = currentEnemy_Base->next;
    
    }
    return false; // La posizione è libera
}
// Funzione che verifica se una posizione (x, y) è occupata da un nemico nella lista
bool Medium_isPositionOccupied(int x, int y, lista_medium_enemy* medium_en) {
  
    p_medium_en currentEnemy_Medium = medium_en;
    
   
    while (currentEnemy_Medium!=NULL) {
        if (!currentEnemy_Medium->m_en->dead && currentEnemy_Medium->m_en->x_ == x && currentEnemy_Medium->m_en->y_ == y) {
            return true; // La posizione è occupata da un nemico vivo
        }
 
        currentEnemy_Medium = currentEnemy_Medium->next;
        
    }
    return false; // La posizione è libera
}


// Funzione che verifica se una posizione (x, y) è occupata da un nemico nella lista
bool Tough_isPositionOccupied(int x, int y, p_tough_en tough_en) {
  
    p_tough_en currentEnemy_Tough = tough_en;
    
   
    while (currentEnemy_Tough!=NULL) {
        if (!currentEnemy_Tough->t_en->dead && currentEnemy_Tough->t_en->x_ == x && currentEnemy_Tough->t_en->y_ == y) {
            return true; // La posizione è occupata da un nemico vivo
        }
 
        currentEnemy_Tough= currentEnemy_Tough->next;
        
    }
    return false; // La posizione è libera
}
