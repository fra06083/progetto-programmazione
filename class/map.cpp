#include "map.hpp"
#include <ctime>
#include <cstdlib>
#include <ncurses.h>

Map::Map()
{
    generateMap();
}
void Map::generateMap()
{

    for (int i = 0; i < MAX_X; i++)
    {
        for (int j = 0; j < MAX_Y; j++)
        {
            if (j == MAX_Y - 1)
            {
                map[j][i] = true;
            }
            else
            {
                map[j][i] = false;
            }
        }
    }
    srand(time(0));
    for (int i = 0; i < MAX_X; i += 10)
    {
        for (int j = 0; j < MAX_Y; j += 5)
        {
            if (rand() % 100 < 20)
            {
                for (int k = i; k < i + 8; k++)
                {
                    map[j][k] = true;
                }
            }
        }
    }
}
bool Map::isPlatform(int x, int y)
{
    if (x < 0 || x >= MAX_X || y < 0 || y >= MAX_Y)
    {
        return false;
    }
    
    return map[y][x];
}
bool Map::platformAbove(int x, int y){
     if (map[y-1][x]){
        return true;
        
     }
     else {
        return false;
        
     }
}
bool Map::platformUnder(int x, int y){
     if (map[y+1][x]){
        return true;
        
     }
     else {
        return false;
        
     }
}

