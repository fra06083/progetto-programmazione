
//comando compilazione: g++ main.cpp savingSystem/SaveLoad.cpp class/layout.cpp class/objects.cpp class/map/room.cpp class/map/map.cpp class/map/platform.cpp class/personaggio.cpp  class/enemy.cpp class/collision.cpp class/proiettile.cpp game.cpp -lncurses -g -o test
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
    Player *player = new Player(MAX_X-START_X+1, MAX_Y-2, 5, map, 40); // il valore 40 è la vita, la prenderà dal salvataggio.
    p_base_en base_enemy = NULL;
   
    p_pro proiettile=NULL;
    Game *game = new Game(layout, map, player, base_enemy, proiettile);

    game->run(); // LOOP per non chiudere il gioco

    return 0;
}