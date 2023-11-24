#include "class/layout.hpp"
#include "class/enemy.hpp"
#include "class/proiettile.hpp"
#include "class/personaggio.hpp"
#include "class/map.hpp"
#include <iostream>
using namespace std;


class Game
{
private:
  Layout *layout;
  Player *player;
  Map *map;
  Nemico *enemy;
  p_pro proiettile;
  bool quit = false;
  int counter=0;

public:
  Game(Layout *l, Map *m, Player *p, Nemico *en, p_pro pr);
  int updateJ(WINDOW* game, Player *p, Map *map, bool isJump, int i);
  void run();

};





