#include "layout.hpp"
#include <cstring>
void Layout::init_screen()
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, height, width);
    game = subwin(stdscr, gheight + 3, gwidth + 3, START_Y, START_X);
}
void Layout::draw_box()
{
    this->clearwin();
    box(stdscr, 0, 0);
    box(game, 0, 0);
    wrefresh(game);
}
void Layout::clearwin()
{
    clear();
    refresh();
}
void Layout::main_menu()
{
    char menu[3][20] = {"NUOVA PARTITA", "SHOP", "ESCI DAL GIOCO"};
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
        ch = wgetch(stdscr);

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
            this->clearwin();
            refresh();
            exit = true;
            if (scelta == 1)
            {
                ingame = true;
                this->draw_box();
                refresh();
                // disegna solo il box, quando avremo la classe Game gestirà lui la partita
                // layout si preoccupa solo di dare il template al gioco come se fossero
                // due componenti diverse
            }
            else if (scelta == 2)
            {
            } // shop fuori gioco???
            else
                refresh();
                endwin();
        }
    }
}