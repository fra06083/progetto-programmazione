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
    info = subwin(stdscr, gheight +3, gwidth+3, 2, gwidth+20);
    getmaxyx(game, gx, gy);
}
void Layout::draw_box()
{
    box(stdscr, 0, 0);
    box(game, 0, 0);
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
void Layout::write_information(int health, int shield, int maxhp, int damage, int gold, int livello, int conto){
    mvwprintw(info, 1, 1, " ___ _____ _ _____ ___ ");
    mvwprintw(info, 2, 1, "/ __|_   _/_\\_   _/ __|");
    mvwprintw(info, 3, 1, "\\__ \\ | |/ _ \\| | \\__ \\");
    mvwprintw(info, 4, 1, "|___/ |_/_/ \\_\\_| |___/");
    mvwprintw(info, 6, 1, "LIVELLO: %i", livello);
    if (shield)
    mvwprintw(info, 7, 1, "VITA: %i+%i/%i", health, shield, maxhp);
    else 
    mvwprintw(info, 8, 1, "VITA: %i/%i", health, maxhp);
    mvwprintw(info, 9, 1, "ORO: %i", gold);
    mvwprintw(info, 10, 1, "DANNO: %i", damage);
    
    if (conto > 0) 
    mvwprintw(info, 14, 1, "RELOADING AMMO....");
    else 
    mvwprintw(info, 14, 1, " ");
    if (livello%5==0 && livello!=0)
    mvwprintw(info, 17, 1, "(!) Per acquistare un oggetto, vai di fianco ad un item.");
    wrefresh(info);
}
void Layout::shop(object* item, int coin){
    mvwprintw(info, 1, 1, " ___ _  _  ___  ___ ");
    mvwprintw(info, 2, 1, "/ __| || |/ _ \\| _ \\");
    mvwprintw(info, 3, 1, "\\__ \\ __ | (_) |  _/");
    mvwprintw(info, 4, 1, "|___/_||_|\\___/|_|  ");
    mvwprintw(info, 6, 1, "Soldi: %i", coin);
    mvwprintw(info, 8, 1, "<========================>");
    mvwprintw(info, 10, 1, "Oggetto: %s", item->name);
    mvwprintw(info, 11, 1, "Descrizione:");
    mvwprintw(info, 12, 1, "%s", item->description);
    mvwprintw(info, 14, 1, "Prezzo: %i", item->price);
    mvwprintw(info, 15, 1, "Livello attuale: %i", item->possession);
    if (item->price > coin){
        mvwprintw(info, 17, 1, "(!) MONETE INSUFFICIENTI");
    } else {
        mvwprintw(info, 17, 1, "V Clicca ENTER per acquistare!");
    }

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

        if (ch == KEY_UP || ch == 'w' || ch == 'W')
        {
            if (scelta > 0)
            {
                scelta--;
            }
            else
            {
                scelta = 2;
            }
        }
        if (ch == KEY_DOWN || ch == 'S' || ch == 's'){
            if (scelta < 2)
            {
                scelta++;
            }
            else
            {
                scelta = 0;
            }
        }
        if (ch == '\n'){
            exit = true;
            return scelta + 1;
        }
    }
        return 0;
}