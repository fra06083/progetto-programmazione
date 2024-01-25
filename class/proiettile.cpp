   #include "proiettile.hpp"
   
    Proiettile::Proiettile(int startX, int startY) : x(startX), y(startY) {}

    void Proiettile::spara() {
        sparato = true;
    }
bool Proiettile::isAttivo() {
    // Rimuovi il controllo this == nullptr
    return sparato && x < 80;  // Assumi che 80 sia il limite dello schermo
}

    void Proiettile::move(WINDOW *game, lista_proiettili *proiettile, char dir) {
            if(proiettile!=NULL){
            mvwaddch(game, y, x, ' ');
            wrefresh(game);
           // napms(50);
            if(dir=='r'){
                x=x+1;
            }
            if(dir=='l'){
                x=x-1;
            }
            mvwaddch(game, y, x, '*');
            wrefresh(game);
            
            mvwaddch(game, y, x, ' ');
            wrefresh(game);
           // napms(50);
            if(dir=='r'){
                x=x+1;
            }
            if(dir=='l'){
                x=x-1;
            }
            mvwaddch(game, y, x, '*');
            wrefresh(game);}

    }


    void Proiettile::draw(WINDOW *game, int playerX, int playerY) {

            x=playerX+1;
            y=playerY;
            mvwaddch(game,y,x, '*');
            wrefresh(game);
    
    }
p_pro head_insert(p_pro& list, Proiettile* pr){
        p_pro tmp=new lista_proiettili;
        tmp->pro= pr;
        tmp->next=list;
        list=tmp;
    
    return list;
}

p_pro tail_delete(p_pro list, Map *map) {
    p_pro prevNode = NULL;
    p_pro currentNode = list;

    while (currentNode != NULL) {
        if (currentNode->pro->x >= 80 || currentNode->pro->x<=2 || map->isPlatform(currentNode->pro->x+1,currentNode->pro->y) || currentNode->pro->colpito) {
            p_pro nextNode = currentNode->next;
            delete currentNode->pro;
            delete currentNode;

            if (prevNode != NULL) {
                prevNode->next = nextNode;
            } else {
                list = nextNode;
            }

            currentNode = nextNode;
        } else {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }

    return list;
}

p_pro pro_tail_delete(p_pro list, Map *map) {
    p_pro prevNode = NULL;
    p_pro currentNode = list;

    while (currentNode != NULL) {
        if (currentNode->pro->x >= 80 || currentNode->pro->x<=2 || map->isPlatform(currentNode->pro->x+1,currentNode->pro->y)) {
            p_pro nextNode = currentNode->next;
            
            delete currentNode->pro;
            delete currentNode;

            if (prevNode != NULL) {
                prevNode->next = nextNode;
            } else {
                list = nextNode;
            }

            currentNode = nextNode;
        } else {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }

    return list;
}

