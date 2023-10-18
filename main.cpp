// #include "class/personaggio.hpp"
// #include "class/map.hpp"
#include "class/layout.hpp"
#include <iostream>
#include <ctime>
#include <cstring>

int main(int argc, char **argv)
{
    Layout *layout = new Layout();
    layout->init_screen();
    layout->main_menu();
    return 0;
}
