#include "room.hpp"
#include "ncurses.h"
#include <iostream>
#include <cstdlib>  


room::room(Map *first_map, int initial_room) {
    current_room = initial_room;
    last_room = initial_room;
    normal_maps[last_room] = first_map;
    room_enemy[last_room]=nullptr;
}

// Genera una nuova stanza (shop o normale) all'occorenza
     Map* room::generate_new_room() {
        this->current_room++;
        this->last_room = this->current_room;

        Map* new_map = new Map;
        if (this->current_room%5==0) {
            new_map->generateShop();
        }
        else{
            new_map->generateMap();
            generate_enemy();
        } 

        // Espande l'array dinamico di mappe
        Map** new_maps = new Map*[this->last_room+1];
        for (int i = 0; i < this->current_room; i++) {
            new_maps[i] = this->normal_maps[i];
        }
        new_maps[this->current_room] = new_map;

        // Dealloca l'array precedente e assegna quello nuovo
        delete[] this->normal_maps;
        this->normal_maps = new_maps; 
         
        return normal_maps[current_room];      
    }

    // Carica una stanza già creata in precedenza
    Map* room::load_room(int room_number) {
        this->current_room=room_number;
        return normal_maps[current_room];
    }
    
    // Ritorna la lista di nemici presenti in una stanza
    p_base_en room::get_current_enemy(){
        return room_enemy[current_room];
    }

    // Genera nuovi nemici alla generazione di una stanza (non shop)
    void room::generate_enemy(){
        Base_en *new_enemy;
        p_base_en* new_enemys = new p_base_en[this->last_room+1];

        for (int i = 0; i < this->current_room; i++) {
            new_enemys[i] = this->room_enemy[i];
        }
        
        if(base_en_counter<3 && medium_en_counter<3){
            base_en_counter++;
        }

        else if(medium_en_counter<3 && base_en_counter>=3){
            base_en_counter=0;
            medium_en_counter++;
        }

        else{
            base_en_counter=0;
            medium_en_counter=0;
            tough_en_counter++;

        }

        for(int i=0; i<base_en_counter; i++){
            int en_X = std::rand() %54 + 24;
            int en_Y = std::rand() % 23-2;
                   
            new_enemy = new Base_en(en_X, en_Y, 'b');
            new_enemys[this->current_room] = e_head_insert(new_enemys[current_room], new_enemy);
            } 
        
        for(int i=0; i<medium_en_counter; i++){
            int en_X = std::rand() %54 + 24;
            int en_Y = std::rand() % 23-2;
        
            new_enemy = new Base_en(en_X, en_Y, 'm');
            new_enemys[this->current_room] = e_head_insert(new_enemys[current_room], new_enemy);
        }

        for (int i=0; i<tough_en_counter; i++){
            int en_X = std::rand() %54 + 24;
            int en_Y = std::rand() % 23-2;
        
            new_enemy = new Base_en(en_X, en_Y, 't');
                new_enemys[this->current_room] = e_head_insert(new_enemys[current_room], new_enemy);
        }

        delete[] this->room_enemy;
        this->room_enemy = new_enemys;
    }

