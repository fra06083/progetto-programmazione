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
    Player *player = new Player(START_X, START_Y, map, layout->game); // refers to layout
    Game *game = new Game(layout, map, player);
    game->run(); // LOOP per non chiudere il gioco

    return 0;
}
