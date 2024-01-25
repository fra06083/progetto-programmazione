#include "SaveLoad.hpp"

void saveGame(objects* obj_info, room* room_info){
    std::ofstream file ("savingSystem/saveFile.txt", std::ios::trunc);

    if (file.is_open()) {
        for (int i=0; i<9; i++){
            file<<obj_info->get_possession(i)<<std::endl;  //Salva il numero di potenziamenti in possesso
        }

        file<<room_info->current_room<<std::endl;  //Salva la stanza corrente

        //Salva i contatori di tutti i nemici
        file<<room_info->base_en_counter<<std::endl;  
        file<<room_info->medium_en_counter<<std::endl;
        file<<room_info->tough_en_counter<<std::endl;

        file.flush();
        file.close();   
    }

    else std::cerr << "Errore nell'apertura del file." << std::endl;
}

void loadGame(objects* obj_info, room* room_info){
    std::ifstream file ("savingSystem/saveFile.txt");
    int value=0;

    if (file.is_open()){
    for (int i=0; i<9; i++){
        file >> value;
        obj_info->load_possession(i,value);  //Carica il numero di potenziamenti in possesso
    }

    //carica e aggiorna le posizioni last room e current room
    file>>room_info->current_room;
    room_info->last_room = room_info->current_room;
    room_info->initial_room=room_info->current_room;

    //Carica i contatori dei nemici;
    file>>room_info->base_en_counter;
    file>>room_info->medium_en_counter;
    file>>room_info->tough_en_counter;

    file.close();
    }

    else std::cerr << "Errore nell'apertura del file." << std::endl;
}

void deletetSave(){
    std::ofstream file ("savingSystem/saveFile.txt", std::ios::trunc);

    if (file.is_open()) {
        for (int i=0; i<13; i++){
            file<<0<<std::endl; //Azzera i salvataggi
        }
        file.close();
    }

    else std::cerr << "Errore nell'apertura del file." << std::endl;
}