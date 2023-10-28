#ifndef MAP_H
#define MAP_H
#define MAX_Y 24
#define MAX_X 80

class Map
{
public:
    // valori max y e max x
    bool map[MAX_Y][MAX_X];
    Map();

    void generateMap();

    bool isPlatform(int x, int y);
};

#endif
