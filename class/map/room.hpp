#include <cstdlib>
#include <cstdio>
#include "map.hpp"


class room {
public:
    int current_room;
    int last_room;
    Map** normal_maps= new Map*[1];  // Array dinamico di puntatori a mappe
    //shop shop_room;

    room(Map *first_map, int initial_room=1);

    void cleanup_maps();
    Map* generate_new_room();
    Map* load_room(int room_number);
    int get_current_room ();
    int get_last_room();
};