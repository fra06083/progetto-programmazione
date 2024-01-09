#include "room.hpp"
#include "ncurses.h"
#include <iostream>
#include <cstdlib>  


room::room(Map *first_map, int initial_room) {
    current_room = initial_room;
    last_room = initial_room;
    normal_maps[last_room-1] = first_map;
}

void room::cleanup_maps() {
    if (normal_maps) {
        for (int i = 0; i < current_room - 1; ++i) {
            delete normal_maps[i];
        }
        delete[] normal_maps;
        normal_maps = nullptr;
    }
}

     Map* room::generate_new_room() {
        this->current_room++;
        this->last_room = this->current_room;

        Map* new_map = new Map;
        if (this->current_room%5==0) new_map->generateShop();
        else new_map->generateMap();

        // Espande l'array dinamico di mappe
        Map** new_maps = new Map*[this->current_room];
        for (int i = 0; i < this->current_room - 1; i++) {
            new_maps[i] = this->normal_maps[i];
        }
        new_maps[this->current_room - 1] = new_map;

        // Dealloca l'array precedente e assegna quello nuovo
        delete[] this->normal_maps;
        this->normal_maps = new_maps; 
         
        return normal_maps[current_room-1];      
    }

    Map* room::load_room(int room_number) {
        this->current_room=room_number;
        return normal_maps[current_room-1];
    }

    int room::get_current_room(){
        return current_room;
    }

    int room::get_last_room(){
        return last_room;
    }
