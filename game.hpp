#include "class/layout.hpp"
#include "class/personaggio.hpp"
#include "class/map.hpp"
class Game
{
private:
  Layout *layout;
  Player *player;
  Map *map;
  bool quit = false;

public:
  Game(Layout *l, Map *m, Player *p);
  void run();
};
