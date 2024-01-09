#include "class/layout.hpp"
#include "class/enemy.hpp"
#include "class/proiettile.hpp"
#include "class/personaggio.hpp"
#include "class/map/map.hpp"
#include "class/map/room.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Game
{
private:
  Layout *layout;
  Player *player;
  Map *map;
  room *rooms;
  platform* temp;
  p_en enemy;
  p_pro proiettile;
  bool quit = false;
  int counter=0;

public:
  Game(Layout *l, Map *m, Player *p, p_en en, p_pro pr);
  int updateJump(WINDOW* game, Player *p, Map *map, bool isJump, int i);
  void run();
  void drawMap (Layout *game_window, Map *game_map);
};




