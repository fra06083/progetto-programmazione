#include "game.hpp"
Game::Game(Layout *l, Map *m, Player *p)
{
    this->layout = l;
    this->map = m;
    this->player = p;
}
void Game::run()
{
    layout->init_screen();
    layout->main_menu();
}