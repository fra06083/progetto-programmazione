#include <ncurses.h>
#include <cstring>
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
    wrefresh(win);
    keypad(win, true);
    curs_set(0);
}
int main() {
    init_game();
    int scelta = 0; 
        while(1) {
        mvwprintw(win, 2, 2, "Nuova Partita");
        mvwprintw(win, 4, 2, "Shop");
        mvwprintw(win, 6, 2, "Esci dal Gioco");
        wrefresh(win);
        switch(getch()) {
              case KEY_UP:
            if (scelta > 0) {
                scelta--;
            }
            break;
        case KEY_DOWN:
            if (scelta < 3) {
                scelta++;
            }
            break;
        }
       }
    endwin(); 
    return 0; 
}
