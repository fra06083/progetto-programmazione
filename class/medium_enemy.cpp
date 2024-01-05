#include "medium_enemy.hpp"

 Medium_en::Medium_en(int x, int y) : x_(x), y_(y) {}
 
 void Medium_en::draw(WINDOW *win)
    { if(!dead){
        mvwprintw(win, y_, x_, "Y");
    }
    }

/*
void Medium_en::move(WINDOW* game, Map *map, int playerX, int playerY, p_base_en base_en, p_medium_en medium_en, p_tough_en tough_en) {
    if (!dead) {
        // Calcola la direzione verso il giocatore
        int deltaX = playerX - x_;
        int deltaY = playerY - y_;

        if (counter_move == 2) {
            // Sposta il nemico verso il giocatore
            if (deltaX > 0 && !isPositionOccupied(x_ + 1, y_,base_en, medium_en, tough_en)) {
                x_++;
            } else if (deltaX < 0 && !isPositionOccupied(x_ - 1, y_,base_en, medium_en, tough_en)) {
                x_--;
            }
            counter_move = 0;
        }
        counter_move = counter_move + 1;

        if (!map->platformUnder(x_, y_)) {
            mvwaddch(game, y_, x_, ' '); // Cancellazione personaggio corrente
            y_ += 1;
            draw(game);
        }
    }
}
*/

    void Medium_en::move(WINDOW* game,Map *map, char c)
    { 
        if(!dead){
        // Calcola la direzione verso il giocatore
        //int deltaX = playerX - x_;
        //int deltaY = playerY - y_;
        if(counter_move==2){
        // Sposta il nemico verso il giocatore
        if (c=='r')
        {
            x_++;
        }
        else if (c=='l')
        {
            x_--;
            
        }
        counter_move=0;
        }
        counter_move=counter_move+1;
        
        //while (!map->platformUnder(x_, y_)){
        if(!map->platformUnder(x_, y_)){ 
            mvwaddch(game, y_, x_, ' '); // Cancellazione personaggio corrente
            y_ += 1;
            
            draw(game);
        }
  }

}



// Funzione per l'inserimento di un nemico all'inizio della lista
p_medium_en e_head_insert(p_medium_en& list, Medium_en *enemy1){
    // Crea un nuovo nodo
    p_medium_en tmp = new lista_medium_enemy;
    // Assegna il nemico al nuovo nodo
    tmp->m_en= enemy1;
    // Collega il nuovo nodo alla lista
    tmp->next = list;
    // Aggiorna la testa della lista
    list = tmp;
    // Restituisci la lista aggiornata
    return list;
}

// Funzione per la rimozione di nemici colpiti dalla lista
p_medium_en e_tail_delete(p_medium_en list, Map *map, p_pro p, Player* player) {
    // Nodo precedente nella lista
    p_medium_en prevNode = NULL;
    // Nodo corrente nella lista
    p_medium_en currentNode = list;
    // Proiettile corrente
    p_pro colpito = p;

    // Itera attraverso i proiettili colpiti
    while (colpito != NULL) {
        // Itera attraverso i nemici nella lista
        while (currentNode != NULL) {
            // Verifica se il proiettile ha colpito il nemico
            if (colpito->pro && currentNode->m_en && 
                (colpito->pro->x + 1 == currentNode->m_en->x_ || 
                 colpito->pro->x - 1 == currentNode->m_en->x_ || 
                 colpito->pro->x == currentNode->m_en->x_) && 
                colpito->pro->y == currentNode->m_en->y_) {
                    if(currentNode->m_en->health<=0){
                // Segna il nemico come morto
                currentNode->m_en->dead = true;
                // Segna il proiettile come colpito
                colpito->pro->colpito = true;

                // Salva il puntatore al prossimo nodo
                p_medium_en nextNode = currentNode->next;

                // Elimina il nemico corrente dalla lista
                delete currentNode->m_en;
                delete currentNode;

                // Aggiorna i collegamenti nella lista
                if (prevNode != NULL) {
                    prevNode->next = nextNode;
                } else {
                    list = nextNode;
                }
                
                // Sposta il puntatore al prossimo nodo
                currentNode = nextNode;
                } 
                else{
                    colpito->pro->colpito = true;
                    currentNode->m_en->health = currentNode->m_en->health - player->damage;
                    prevNode = currentNode;
                    currentNode = currentNode->next;
                }
            } else {
                // Se il nemico non è stato colpito, passa al nodo successivo
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
        }

        // Reinizializza il puntatore al nodo corrente e al nodo precedente all'inizio delle liste
        currentNode = list;
        prevNode = NULL;
        // Passa al prossimo proiettile colpito
        colpito = colpito->next;
    }

    // Restituisci la lista aggiornata
    return list;
}


