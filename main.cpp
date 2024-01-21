
//comando compilazione: g++ main.cpp class/layout.cpp class/objects.cpp class/map/room.cpp class/map/map.cpp class/map/platform.cpp class/personaggio.cpp  class/enemy.cpp class/collision.cpp class/proiettile.cpp game.cpp -lncurses -o test
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
    Player *player = new Player(MAX_X-START_X+1, MAX_Y-2,8, map, 100); // il valore 100 è la vita, la prenderà dal salvataggio.
    p_base_en base_enemy = NULL;
   
    p_pro proiettile=NULL;
    Game *game = new Game(layout, map, player, base_enemy, proiettile);

    game->run(); // LOOP per non chiudere il gioco

    return 0;
}