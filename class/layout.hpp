#include <ncurses.h>
#define START_X 2
#define START_Y 2

#include "objects.hpp"
class Layout
{
private:
  const int gwidth = 80;
  const int gheight = 24;
  bool ingame = false;

public:
  int width, height, gx, gy;
  WINDOW *game, *info;
  void init_screen();
  int main_menu();
  void game_over();
  void shop(objects items);
  void write_information(int health, int shield, int maxhp, int damage);
  void draw_box();
  void clearwin();
  void draw_player(int x, int y);
  
};