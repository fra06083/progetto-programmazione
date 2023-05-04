#ifndef MAP_H
#define MAP_H

#include "map.cpp"
#define MAX_X 80
#define MAX_Y 24
class Map {
public:
    bool map[MAX_Y][MAX_X];
    Map() {
        generateMap();
    }

    void generateMap() {
        
        for (int i = 0; i < MAX_X; i++) {
            for (int j = 0; j < MAX_Y; j++) {
                if (j == MAX_Y - 1) {
                    map[j][i] = true;
                } else {
                    map[j][i] = false;
                }
            }
        }
        srand(time(0));
        for (int i = 0; i < MAX_X; i += 10) {
            for (int j = 0; j < MAX_Y; j += 5) {
                if (rand() % 100 < 20) {
                    for (int k = i; k < i + 8; k++) {
                        map[j][k] = true;
                    }
                }
            }
        }
    }

    bool isPlatform(int x, int y) {
        if (x < 0 || x >= MAX_X || y < 0 || y >= MAX_Y) {
            return false;
        }
        return map[y][x];
    }
};





#endif
