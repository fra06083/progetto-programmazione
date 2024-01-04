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

     void room::generate_new_room(int last_room) {
        Map* new_map = new Map;
        new_map->generateMap();

        // Espande l'array dinamico di mappe
        Map** new_maps = new Map*[this->current_room];
        for (int i = 0; i < this->current_room - 1; ++i) {
            new_maps[i] = this->normal_maps[i];
        }
        new_maps[this->current_room - 1] = new_map;

        // Dealloca l'array precedente e assegna quello nuovo
        delete[] this->normal_maps;
        this->normal_maps = new_maps;

        this->current_room++;
        this->last_room = this->current_room;
    }

    /*
    void room::save_room(Map room_layout, int current_room) const {
        
    }

    void room::load_room(int room_number) {
        if (room_number >= 1 && room_number < current_room) {
            // Carica la mappa desiderata
            Map* loaded_map = normal_maps[room_number - 1];
            // Puoi eseguire altre operazioni necessarie con la mappa caricata
            // loaded_map->someOperation();
            std::cout << "Mappa per la stanza " << room_number << " caricata." << std::endl;
        } else {
            std::cout << "Numero di stanza non valido." << std::endl;
        }
    }*/

    int room::get_current_room(){
        return current_room;
    }

    int room::get_last_room(){
        return last_room;
    }
