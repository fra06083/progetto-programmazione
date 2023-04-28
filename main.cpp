#include <ncurses.h>
// CLASSI FUNZIONI DA IMPLEMENTARE
using namespace std;
//  endwin(); termina il gioco

int max_x, max_y;
WINDOW *win;
// inizializza la schermata mx max x schermata, my max y schermata
void init_game(){
    initscr();
    noecho();
    getmaxyx(stdscr, max_y, max_x);
    win = newwin(max_y, max_x, 0, 0);
    refresh();
    box(win, 0, 0);
    keypad(win, true);
}
int main(){
    init_game();
    mvwprintw(win, 1, 1, "Main Menu");
    wrefresh(win);
    int c = getch();
    endwin();
    return 0;
}
