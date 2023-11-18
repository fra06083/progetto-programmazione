#include "class/layout.hpp"
#include "class/enemy.hpp"
#include "class/personaggio.hpp"
#include "class/map.hpp"


class Game
{
private:
  Layout *layout;
  Player *player;
  Map *map;
  Nemico *enemy;
  bool quit = false;

public:
  Game(Layout *l, Map *m, Player *p, Nemico *en);
  void run();
};
