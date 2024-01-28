#include "class/layout.hpp"
#include "class/collision.hpp"
#include "class/proiettile.hpp"
#include "class/objects.hpp"
#include "class/personaggio.hpp"
#include "class/map/map.hpp"
#include "class/map/room.hpp"
#include "savingSystem/SaveLoad.hpp"
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
  Map* next_map = new Map;
  room *rooms;
  p_base_en base_en;
  p_pro proiettile;
  objects* all_obj=new objects;
  object* current_obj;
  bool quit , gameover = false;
  bool buy=false;
  int counter=0;
  int random_number=rand();
  char R_shop_symbol[4];
  char L_shop_symbol[4];

public:
  Game(Layout *l, Map *m, Player *p, p_base_en b_en, p_pro pr);
  int updateJump(WINDOW* game, Player *p, Map *map, bool isJump, int i);
  p_base_en b_update_enemy( p_base_en base_en,WINDOW* game, Map *map, Player *player, p_pro proiettile);
 
  void drawMap (Layout *game_window, Map *game_map);
  void shop_control();
  void gameLOOP();
  void run();
  
};