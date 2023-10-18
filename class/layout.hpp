#include <ncurses.h>
#define START_X 2
#define START_Y 2
class Layout {
private:
 int width, height;
 const int gwidth = 50;
 const int gheight = 8;
 bool ingame = false;
 WINDOW *game;
public:
  void init_screen();
  void main_menu();
  void draw_box();
  void clearwin();
};