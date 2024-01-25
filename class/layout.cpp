#include "layout.hpp"
#include <cstring>
void Layout::init_screen()
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, height, width);
    game = subwin(stdscr, gheight + 3, gwidth + 1, START_Y, START_X);
    getmaxyx(game, gx, gy);
}
void Layout::draw_box()
{
    box(stdscr, 0, 0);
    box(game, 0, 0);
    refresh();
}
void Layout::clearwin()
{
    clear();
    refresh();
}
int Layout::main_menu()
{
    char menu[3][20] = {"NUOVA PARTITA", "CARICA PARTITA", "ESCI DAL GIOCO"};
    bool exit = false;
    int ch;
    int scelta = 0;
    while (!exit)
    {
        for (int i = 0; i < 3; i++)
        {
            if (scelta == i)
                wattron(stdscr, A_REVERSE);
            mvwprintw(stdscr, (height / 2) + (4 * i) - 4, width / 2 - strlen(menu[i]) / 2, "%s", menu[i]);
            wattroff(stdscr, A_REVERSE);
        }

        box(stdscr, 0, 0);
        refresh();
        ch = getch();

        switch (ch)
        {
        case KEY_UP:
            if (scelta > 0)
            {
                scelta--;
            }
            else
            {
                scelta = 2;
            }
            break;
        case KEY_DOWN:
            if (scelta < 2)
            {
                scelta++;
            }
            else
            {
                scelta = 0;
            }
            break;
        case '\n':
            exit = true;
            return scelta + 1;
        }
    }
        return 0;
}