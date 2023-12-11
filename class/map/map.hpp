#ifndef MAP_H
#define MAP_H
#define MAX_Y 24
#define MAX_X 80
#include "platform.hpp"
#include <ctime>
#include <cstdlib>
#include <ncurses.h>


class Map
{
private:
    
public:
    platform *platf[54];
    // valori max y e max x
    bool map[MAX_Y][MAX_X];
    Map();

    void generateMap();

    bool isPlatform(int x, int y);
    bool platformAbove(int x, int y);
    bool platformUnder(int x, int y);
    int choose_platform();
    bool probability(int prob);
    void make_readable (platform *platf[]);
    void generate_platform (platform *platf[], int cell_num);
    void cell (int cell_num, platform *platf[]);
};

#endif
