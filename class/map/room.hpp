#include <cstdlib>
#include <cstdio>
#include "map.hpp"
#include "../enemy.hpp"


class room {
public:
    int current_room;
    int last_room;
    int base_en_counter=0;
    int medium_en_counter=0;
    int tough_en_counter=0;
    Map** normal_maps= new Map*[1];  // Array dinamico di puntatori a mappe
    p_base_en* room_enemy= new p_base_en[1];
    

    room(Map *first_map, int initial_room=0);

    Map* generate_new_room();
    Map* load_room(int room_number);
    p_base_en get_current_enemy();
    void generate_enemy();
};
