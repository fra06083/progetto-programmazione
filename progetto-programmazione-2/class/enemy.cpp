#include <ncurses.h>
#include <iostream>
#include <ctime>
#include "enemy.hpp"

    Nemico::Nemico(int x, int y) : x_(x), y_(y) {}

    void Nemico::draw(WINDOW *win)
    { if(!dead){
        mvwprintw(win, y_, x_, "X");
    }
    }
    void Nemico::cancella(WINDOW *win)
    {
        mvwprintw(win, y_, x_, " ");
    }
    void Nemico::move(WINDOW* game,Map *map, int playerX, int playerY)
    { 
        if(!dead){
        // Calcola la direzione verso il giocatore
        int deltaX = playerX - x_;
        int deltaY = playerY - y_;
        if(counter_move==4){
        // Sposta il nemico verso il giocatore
        if (deltaX > 0)
        {
            x_++;
        }
        else if (deltaX < 0)
        {
            x_--;
            
        }
        counter_move=0;
        }
        counter_move=counter_move+1;
        /*
        if (deltaY > 0)
        {
            y_++;
        }
        else if (deltaY < 0)
        {
            y_--;
        }
        */
        //while (!map->platformUnder(x_, y_)){
        if(!map->platformUnder(x_, y_)){ 
            mvwaddch(game, y_, x_, ' '); // Cancellazione personaggio corrente
            y_ += 1;
            
            draw(game);
        }
  }
}


// Funzione per l'inserimento di un nemico all'inizio della lista
p_en e_head_insert(p_en& list, Nemico *enemy1){
    // Crea un nuovo nodo
    p_en tmp = new lista_enemy;
    // Assegna il nemico al nuovo nodo
    tmp->enemy = enemy1;
    // Collega il nuovo nodo alla lista
    tmp->next = list;
    // Aggiorna la testa della lista
    list = tmp;
    // Restituisci la lista aggiornata
    return list;
}

// Funzione per la rimozione di nemici colpiti dalla lista
p_en e_tail_delete(p_en list, Map *map, p_pro p) {
    // Nodo precedente nella lista
    p_en prevNode = NULL;
    // Nodo corrente nella lista
    p_en currentNode = list;
    // Proiettile corrente
    p_pro colpito = p;

    // Itera attraverso i proiettili colpiti
    while (colpito != NULL) {
        // Itera attraverso i nemici nella lista
        while (currentNode != NULL) {
            // Verifica se il proiettile ha colpito il nemico
            if (colpito->pro && currentNode->enemy && 
                (colpito->pro->x + 1 == currentNode->enemy->x_ || 
                 colpito->pro->x - 1 == currentNode->enemy->x_ || 
                 colpito->pro->x == currentNode->enemy->x_) && 
                colpito->pro->y == currentNode->enemy->y_) {
                // Segna il nemico come morto
                currentNode->enemy->dead = true;
                // Segna il proiettile come colpito
                colpito->pro->colpito = true;

                // Salva il puntatore al prossimo nodo
                p_en nextNode = currentNode->next;

                // Elimina il nemico corrente dalla lista
                delete currentNode->enemy;
                delete currentNode;

                // Aggiorna i collegamenti nella lista
                if (prevNode != NULL) {
                    prevNode->next = nextNode;
                } else {
                    list = nextNode;
                }

                // Sposta il puntatore al prossimo nodo
                currentNode = nextNode;
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
