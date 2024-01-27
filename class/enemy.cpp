#include "enemy.hpp"

    Base_en::Base_en(int x, int y, char type){
        x_=x;
        y_=y;
        
        if(type=='b'){
            health=3;
            counter_move=0;
            damage=2;
            gold=3;
            dead =false;
            speed=2;
            simbolo='X';
 
        }
        if(type=='m'){
            health=5;
            counter_move=0;
            damage=4;
            gold=5;
            dead =false;
            speed=2;
            simbolo='Y';
        }
        if(type=='t'){
            health=7;
            counter_move=0;
            damage=6;
            gold=10;
            dead =false;
            speed=3;
            simbolo='Z';
        }
    }
    bool Base_en::enemyattack(int playerX, int playerY){
        return (playerY == y_ && (playerX-1 == x_ || playerX+1 == x_));
    }
    void Base_en::draw(WINDOW *win)
    { 
        if(!dead){
        if(simbolo=='X'){
        mvwprintw(win, y_, x_, "X");
        }
        if(simbolo=='Y'){
        mvwprintw(win, y_, x_, "Y");
        }
        if(simbolo=='Z'){
        mvwprintw(win, y_, x_, "Z");
        }
      
    }
    }
    void Base_en::sparareProiettile( int playerX, int playerY) {
    if (!dead && simbolo!='X') {
        // Calcola la direzione in base alla posizione del player
        char direzione;
        if (playerX > x_) {
            direzione = 'r'; // il giocatore è a destra del nemico
        } else {
            direzione = 'l'; // il giocatore è a sinistra del nemico
        }

        // Crea un nuovo proiettile alla posizione del nemico
        Proiettile *nuovoProiettile = new Proiettile(x_, y_);
        nuovoProiettile->spara();

        // Imposta la direzione del proiettile
        nuovoProiettile->dir=direzione; // Assumendo che ci sia un metodo setDirezione

        // Aggiungi il proiettile alla lista
        head_insert(proiettili, nuovoProiettile);
    }
}
  
    void Base_en::move(WINDOW* game,Map *map, char c)
    { 
        if(!dead){
            if(simbolo!='Y'){
        // Calcola la direzione verso il giocatore
        //int deltaX = playerX - x_;
        //int deltaY = playerY - y_;
        if(counter_move==speed){
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
        }
        //while (!map->platformUnder(x_, y_)){
        if(!map->platformUnder(x_, y_)){ 
            mvwaddch(game, y_, x_, ' '); // Cancellazione personaggio corrente
            y_ += 1;
            
            draw(game);
        }
  }

}



// Funzione per l'inserimento di un nemico all'inizio della lista
p_base_en e_head_insert(p_base_en& list, Base_en *enemy1){
    // Crea un nuovo nodo
    p_base_en tmp = new lista_base_enemy;
    // Assegna il nemico al nuovo nodo
    tmp->b_en= enemy1;
    // Collega il nuovo nodo alla lista
    tmp->next = list;
    // Aggiorna la testa della lista
    list = tmp;
    // Restituisci la lista aggiornata
    return list;
}

// Funzione per la rimozione di nemici colpiti dalla lista
p_base_en e_tail_delete(p_base_en list, Map *map, p_pro p, Player* player) {
    // Nodo precedente nella lista
    p_base_en prevNode = NULL;
    // Nodo corrente nella lista
    p_base_en currentNode = list;
    // Proiettile corrente
    p_pro colpito = p;

    // Itera attraverso i proiettili colpiti
    while (colpito != NULL) {
        // Itera attraverso i nemici nella lista
        while (currentNode != NULL) {
            // Verifica se il proiettile ha colpito il nemico
            if (colpito->pro && currentNode->b_en && 
                (colpito->pro->x + 2 == currentNode->b_en->x_ || 
                 colpito->pro->x - 2 == currentNode->b_en->x_ || 
                 colpito->pro->x + 1 == currentNode->b_en->x_ || 
                 colpito->pro->x - 1 == currentNode->b_en->x_ ||
                 colpito->pro->x == currentNode->b_en->x_) && 
                colpito->pro->y == currentNode->b_en->y_) {
                if(currentNode->b_en->health<=0){// Segna il nemico come morto
                currentNode->b_en->dead = true;
                player->Valuta= player->Valuta +currentNode->b_en->gold;
                // Segna il proiettile come colpito
                colpito->pro->colpito = true;
                
                // Salva il puntatore al prossimo nodo
                p_base_en nextNode = currentNode->next;

                // Elimina il nemico corrente dalla lista
                delete currentNode->b_en;
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
                    currentNode->b_en->health=currentNode->b_en->health - player->damage;
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

