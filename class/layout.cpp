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
    info = subwin(stdscr, gheight +3, gwidth+5, 2, gwidth+5);
    getmaxyx(game, gx, gy);
}
void Layout::draw_box()
{
    box(stdscr, 0, 0);
    box(game, 0, 0);
    box(info, 0, 0);
    refresh();
}
void Layout::game_over(){
    clear();
    mvwprintw(stdscr, (height / 2) - 4, width / 2 - strlen("  ___   _   __  __ ___    _____   _____ ___ ") / 2, "   ___   _   __  __ ___    _____   _____ ___ ");
    mvwprintw(stdscr, (height / 2)  - 4 + 1, width / 2 - strlen("  ___   _   __  __ ___    _____   _____ ___ ") / 2, "  / __| /_\\ |  \\/  | __|  / _ \\ \\ / / __| _ \\");
    mvwprintw(stdscr, (height / 2) - 4  + 2, width / 2 - strlen("   ___   _   __  __ ___    _____   _____ ___ ") / 2, " | (_ |/ _ \\| |\\/| | _|  | (_) \\ V /| _||   /");
    mvwprintw(stdscr, (height / 2) - 4 + 3, width / 2 - strlen("   ___   _   __  __ ___    _____   _____ ___ ") / 2, "  \\___/_/ \\_\\_|  |_|___|  \\___/ \\_/ |___|_|_\\");
    mvwprintw(stdscr, (height / 2) - 4 + 5, width / 2 + strlen("Try Again?"), "Try Again?");
    refresh();
    napms(5000);
}
void Layout::write_information(int health, int shield, int maxhp, int damage){
    mvwprintw(info, 1, 1, " ___ _____ _ _____ ___ ");
    mvwprintw(info, 2, 1, "/ __|_   _/_\\_   _/ __|");
    mvwprintw(info, 3, 1, "\\__ \\ | |/ _ \\| | \\__ \\");
    mvwprintw(info, 4, 1, "|___/ |_/_/ \\_\\_| |___/");
    if (shield)
    mvwprintw(info, 6, 1, "VITA: %i+%i/%i", health, shield, maxhp);
    else
    mvwprintw(info, 6, 1, "VITA: %i/%i", health, maxhp);
    mvwprintw(info, 7, 1, "DANNO: %i", damage);
    wrefresh(info);
}
void Layout::shop(objects items){
    mvwprintw(info, 1, 1, " ___ _  _  ___  ___ ");
    mvwprintw(info, 2, 1, "/ __| || |/ _ \\| _ \\");
    mvwprintw(info, 3, 1, "\\__ \\ __ | (_) |  _/");
    mvwprintw(info, 4, 1, "|___/_||_|\\___/|_|  ");
    wrefresh(info);
}
void Layout::clearwin()
{
    clear();
    refresh();
}
int Layout::main_menu()
{
    clear();
    char menu[3][20] = {"NUOVA PARTITA", "CONTINUA PARTITA", "ESCI DAL GIOCO"};
    bool exit = false;
    int ch;
    int scelta = 0;
    while (!exit)
    {
        wattron(stdscr, A_BOLD);
        mvwprintw(stdscr, (height / 2)  - 10, width / 2 - strlen("@'s @dventure! ") / 2, " @'s @dventure!");
        wattroff(stdscr, A_BOLD);
        mvwprintw(stdscr, (height / 2) + (4 * 3) - 4, width / 2 - strlen("(!) Ricorda di avviare in schermo intero") / 2, "(!) Ricorda di avviare in schermo intero");
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