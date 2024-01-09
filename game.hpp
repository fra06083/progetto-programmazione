#include "class/layout.hpp"
//#include "class/base_enemy.hpp"
//#include "class/medium_enemy.hpp"
//#include "class/tough_enemy.hpp"
#include "class/collision.hpp"
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
  p_base_en base_en;
  p_medium_en medium_en;
  p_tough_en tough_en;
  p_pro proiettile;
  bool quit = false;
  int counter=0;

public:
  Game(Layout *l, Map *m, Player *p, p_base_en b_en, p_medium_en m_en, p_tough_en tough_enemy, p_pro pr);
  int updateJump(WINDOW* game, Player *p, Map *map, bool isJump, int i);
  p_base_en b_update_enemy( p_base_en base_en,p_medium_en medium_en, p_tough_en tough_en,WINDOW* game, Map *map, Player *player, p_pro proiettile);
  p_medium_en m_update_enemy( p_base_en base_en,p_medium_en medium_en, p_tough_en tough_en,WINDOW* game, Map *map, Player *player, p_pro proiettile);
  p_tough_en t_update_enemy( p_base_en base_en,p_medium_en medium_en, p_tough_en tough_en,WINDOW* game, Map *map, Player *player, p_pro proiettile);
  void drawMap (Layout *game_window, Map *game_map);
  void run();
  
};





