#include "map.hpp"

/* Tutto ciò che è una piattaforma viene segnato da una matrice bool map[j][i] = true
   in modo che sia poi riconosciuto dalla funzione is platform e lo traduca in "=" */

Map::Map(){
    generateMap();
}

void Map::generateMap(){  

    for (int i = 0; i < MAX_X; i++)  // Creazione del terreno
    {
        for (int j = 0; j < MAX_Y; j++)
        {
            if (j == MAX_Y - 1)
            {
                map[j][i] = true;
            }
            else
            {
                map[j][i] = false;
            }
        }
    }
    srand(time(0));
        
    int cell_num=rand()%4+9;  //scelta della prima cella tra 9-12

    switch(cell_num){  // Scelta randomica della piattaforma e posizionamento nella cella 
        case 9:
            generate_platform (platf, 9);
        
            if (probability(30)){
                generate_platform (platf, 11);
            }
            generate_platform (platf, 6);
            if (probability(10)) generate_platform(platf, 8);

            if (probability(50)){
                generate_platform (platf, 1);
                if (probability(30)) generate_platform(platf, 3);  
            }
            else {
                generate_platform (platf, 3);
                if (probability(30)) generate_platform(platf, 1);
            }
        break;

        case 10:
            generate_platform (platf, 10);
            
            if (probability(30)){
                generate_platform (platf, 12);
            }

            if (probability(50)){
                generate_platform (platf, 5);
                if (probability(30)) generate_platform(platf, 7);

                generate_platform (platf, 2);
            }
            else {
                generate_platform (platf, 7);
                if (probability(30)) generate_platform(platf, 5);

                if (probability(50)){
                    generate_platform (platf, 2);
                    if (probability(30)) generate_platform(platf, 4);
                }
                else {
                    generate_platform (platf, 4);
                    if (probability(30)) generate_platform(platf, 2);
                }
            }
        break;

        case 11:
            generate_platform (platf, 11);
            
            if (probability(30)){
                generate_platform (platf, 9);
            }

            if (probability(50)){
                generate_platform (platf, 6);
                if (probability(30)) generate_platform(platf, 8);

                if (probability(50)){
                    generate_platform (platf, 1);
                    if (probability(30)) generate_platform(platf, 3);
                }
                else {
                    generate_platform (platf, 3);
                    if (probability(30)) generate_platform(platf, 1);
                }
            }
            else {
                generate_platform (platf, 8);
                if (probability(30)) generate_platform(platf, 6);

                generate_platform(platf, 3);
            }
        break;

        case 12:
            generate_platform (platf, 12);
        
            if (probability(30)){
                generate_platform (platf, 10);
            }
            generate_platform (platf, 7);
            if (probability(10)) generate_platform(platf, 5);

            if (probability(50)){
                generate_platform (platf, 2);
                if (probability(30)) generate_platform(platf, 4);
            }
            else {
                generate_platform (platf, 4);
                if (probability(30)) generate_platform(platf, 2);
            }
        break;
        }
    
}

// Funzione usata per vedere se è presente una piattaforma in una data posizione
bool Map::isPlatform(int x, int y){  
    if (x < 0 || x >= MAX_X || y < 0 || y >= MAX_Y)
    {
        return false;
    }
    
    return map[y][x];
}

bool Map::platformAbove(int x, int y){
     if (map[y-1][x]){
        return true;
        
     }
     else {
        return false;
        
     }
}

bool Map::platformUnder(int x, int y){
     if (map[y+1][x]){
        return true;
        
     }
     else {
        return false;
        
     }
}

// Sceglie uno dei 10 teamplate casualmente
int Map::choose_platform (){
    return rand()%10+1;
}


bool Map::probability(int prob) {
    return rand() % 100 < prob;
}

// Rende true la matrice nelle psizioni delle piattaforme
void Map::make_readable (platform *platf[]){
    int number_of_platforms = platf[0]->platN;
    for (int i=0; i<number_of_platforms;i++){
           for(int j=0; j<platf[i]->width; j++){
                map[platf[i]->y] [platf[i]->x++]= true;
            }
    }
}

// Sceglie la piattaforma, la cella e rende leggibile la paittaforma
void Map::generate_platform (platform *platf[], int cell_num){

    platform::platformType(platf, choose_platform());
    cell (cell_num, platf);
    make_readable(platf);

    // Condizioni per le piattaforme riempitive
    if (cell_num == 4 || cell_num == 8 || cell_num == 12) cell_num --;
    if (cell_num == 9 || cell_num == 10 || cell_num == 11 || cell_num == 12) cell_num = cell_num - 4;
    platform::platformType(platf, 0);
    cell (cell_num, platf);
    make_readable(platf);

    if (cell_num == 2 || cell_num == 3){
        cell_num--;
        platform::platformType(platf, 0);
        cell (cell_num, platf);
        make_readable(platf);
    }
}


// La mappa è divisa in 12 celle e all'interno di ognuna di queste viene posizionata una piattaforma
void Map::cell(int cell_num, platform *platf[]){
    int number_of_platforms = platf[0]->platN;
    switch(cell_num){
    case 1:
    for (int i=0; i<number_of_platforms; i++ ){
        platf[i]->x=platf[i]->x+0;
        platf[i]->y=platf[i]->y+0;
    }
    break;

    case 2:
    for (int i=0; i<number_of_platforms; i++ ){
        platf[i]->x=platf[i]->x+20;
        platf[i]->y=platf[i]->y+0;
    }
    break;

    case 3:
    for (int i=0; i<number_of_platforms; i++ ){
        platf[i]->x=platf[i]->x+40;
        platf[i]->y=platf[i]->y+0;
    }
    break;

    case 4:
    for (int i=0; i<number_of_platforms; i++ ){
        platf[i]->x=platf[i]->x+60;
        platf[i]->y=platf[i]->y+0;
    }
    break;

    case 5:
    for (int i=0; i<number_of_platforms; i++ ){
        platf[i]->x=platf[i]->x+0;
        platf[i]->y=platf[i]->y+8;
    }
    break;

    case 6:
    for (int i=0; i<number_of_platforms; i++ ){
        platf[i]->x=platf[i]->x+20;
        platf[i]->y=platf[i]->y+8;
    }
    break;

    case 7:
    for (int i=0; i<number_of_platforms; i++ ){
        platf[i]->x=platf[i]->x+40;
        platf[i]->y=platf[i]->y+8;
    }
    break;

    case 8:
    for (int i=0; i<number_of_platforms; i++ ){
        platf[i]->x=platf[i]->x+60;
        platf[i]->y=platf[i]->y+8;
    }
    break;

    case 9:
    for (int i=0; i<number_of_platforms; i++ ){
        platf[i]->x=platf[i]->x+0;
        platf[i]->y=platf[i]->y+16;
    }
    break;

    case 10:
    for (int i=0; i<number_of_platforms; i++ ){
        platf[i]->x=platf[i]->x+20;
        platf[i]->y=platf[i]->y+16;
    }
    break;

    case 11:
    for (int i=0; i<number_of_platforms; i++ ){
        platf[i]->x=platf[i]->x+40;
        platf[i]->y=platf[i]->y+16;
    }
    break;

    case 12:
    for (int i=0; i<number_of_platforms;i++ ){
        platf[i]->x=platf[i]->x+60;
        platf[i]->y=platf[i]->y+16;
    }
    break;

    default:
        for (int i=0; i<54; i++ ){
        platf[i]->x=platf[i]->x+0;
        platf[i]->y=platf[i]->y+0;
    }
    break;
    }
}

/*
CELLE:

|=============================================================================|
|                 |                   |                   |                   |
|                 |                   |                   |                   |
|        1        |         2         |         3         |         4         |
|                 |                   |                   |                   |
|                 |                   |                   |                   |
|                 |                   |                   |                   |
|=============================================================================|
|                 |                   |                   |                   |
|                 |                   |                   |                   |
|                 |                   |                   |                   |
|        5        |         6         |         7         |         8         |
|                 |                   |                   |                   |
|                 |                   |                   |                   |
|                 |                   |                   |                   |
|=============================================================================|
|                 |                   |                   |                   |
|                 |                   |                   |                   |
|                 |                   |                   |                   |
|        9        |        10         |        11         |         12        |
|                 |                   |                   |                   |
|                 |                   |                   |                   |
|                 |                   |                   |                   |
|=============================================================================|
*/