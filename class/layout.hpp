#include <ncurses.h>
#define START_X 2
#define START_Y 2
class Layout
{
private:
  const int gwidth = 80;
  const int gheight = 24;
  bool ingame = false;

public:
  int width, height, gx, gy;
  WINDOW *game;
  void init_screen();
  int main_menu();
  void draw_box();
  void clearwin();
  void draw_player(int x, int y);
};