
//comando compilazione: g++ main.cpp class/layout.cpp class/map.cpp class/personaggio.cpp  class/enemy.cpp class/proiettile.cpp game.cpp -lncurses -o test
// #include "class/personaggio.hpp"
// #include "class/map.hpp"
#include "game.hpp"
#include <iostream>
#include <ctime>
#include <cstring>

int main(int argc, char **argv)
{
    // qui faremo la dichiarazione dei puntatori con la macroclasse che può gestirli
    Layout *layout = new Layout();
    Map *map = new Map();
    Player *player = new Player(MAX_X-START_X+1, MAX_Y-2,8, map); // refers to layout
    Nemico *enemy = new Nemico(50,12);
    p_pro proiettile=NULL;
    Game *game = new Game(layout, map, player, enemy,proiettile);
    game->run(); // LOOP per non chiudere il gioco

    return 0;
}