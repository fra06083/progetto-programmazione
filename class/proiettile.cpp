 #include "proiettile.hpp"

Proiettile::Proiettile(int startX, int startY) : x(startX), y(startY) {}

// Marca il proiettile come sparato.
void Proiettile::spara() {
    sparato = true;
}

// Verifica se il proiettile è attivo (sparato e non oltre il limite dello schermo).
bool Proiettile::isAttivo() {
 
    return sparato && x < 78;  
}

// Muove il proiettile nella direzione specificata e aggiorna la sua posizione sullo schermo.
void Proiettile::move(WINDOW *game, lista_proiettili *proiettile, char dir) {
    if(proiettile != NULL){
        
        mvwaddch(game, y, x, ' ');
        wrefresh(game);
        // Aggiorna la posizione del proiettile in base alla direzione
        if(dir == 'r') x += 1;
        if(dir == 'l') x -= 1;
      
        mvwaddch(game, y, x, '*');
        wrefresh(game);
    }
}

// Disegna il proiettile nella posizione iniziale vicino al giocatore.
void Proiettile::draw(WINDOW *game, int playerX, int playerY) {
    x = playerX + 1; 
    y = playerY;
   
    mvwaddch(game, y, x, '*');
    wrefresh(game);
}

// Inserisce un nuovo proiettile all'inizio della lista dei proiettili.
p_pro head_insert(p_pro& list, Proiettile* pr) {
    p_pro tmp = new lista_proiettili;
    tmp->pro = pr;
    tmp->next = list;
    list = tmp;
    return list;
}

// Elimina i proiettili dalla coda della lista che hanno superato i limiti dello schermo o colpito una piattaforma.
p_pro tail_delete(p_pro list, Map *map) {
    p_pro prevNode = NULL;
    p_pro currentNode = list;
    while (currentNode != NULL) {
        // Condizione per eliminare il proiettile
        if (currentNode->pro->x >= 80 || currentNode->pro->x <= 2 || map->isPlatform(currentNode->pro->x + 1, currentNode->pro->y) || currentNode->pro->colpito) {
            p_pro nextNode = currentNode->next;
            delete currentNode->pro;
            delete currentNode;
            
            if (prevNode != NULL) prevNode->next = nextNode;
            else list = nextNode;
            currentNode = nextNode;
        } else {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    return list;
}

// `tail_delete` che considera anche l'interazione con il giocatore.
p_pro pro_tail_delete(p_pro list, Map *map, Player* player) {
    p_pro prevNode = NULL;
    p_pro currentNode = list;
    while (currentNode != NULL) {
        // serve eliminare il proiettile al il contatto con il giocatore
        if (currentNode->pro->x >= 80 || currentNode->pro->x <= 2 ||
            ((player->x == currentNode->pro->x || player->x + 1 == currentNode->pro->x || player->x - 1 == currentNode->pro->x) && player->y == currentNode->pro->y) ||
            map->isPlatform(currentNode->pro->x + 1, currentNode->pro->y)) {
            p_pro nextNode = currentNode->next;
            delete currentNode->pro;
            delete currentNode;
            
            if (prevNode != NULL) prevNode->next = nextNode;
            else list = nextNode;
            currentNode = nextNode;
        } else {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    return list;
}
