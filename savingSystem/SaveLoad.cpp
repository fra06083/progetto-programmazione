#include "SaveLoad.hpp"

void saveGame(objects* obj_info, Player* player_info){
    std::ofstream file ("savingSystem/saveFile.txt", std::ios::trunc);

    if (file.is_open()) {
        for (int i=0; i<9; i++){
            file<<obj_info->get_possession(i)<<std::endl;  //Salva il numero di potenziamenti in possesso
        }

        file<<player_info->health<<std::endl;
        file<<player_info->shield<<std::endl;
        file<<player_info->Valuta<<std::endl;

        file.flush();
        file.close();   
    }

    else std::cerr << "Errore nell'apertura del file." << std::endl;
}

void loadGame(objects* obj_info, Player* player_info){
    std::ifstream file ("savingSystem/saveFile.txt");
    int value=0;

    if (file.is_open()){
    for (int i=0; i<9; i++){
        file >> value;
        obj_info->load_possession(i,value);  //Carica il numero di potenziamenti in possesso
    }

    file>>player_info->health;
    file>>player_info->shield;
    file>>player_info->Valuta;
    

    file.close();
    }

    else std::cerr << "Errore nell'apertura del file." << std::endl;
}

void deletetSave(){
    std::ofstream file ("savingSystem/saveFile.txt", std::ios::trunc);

    if (file.is_open()) {
        for (int i=0; i<9; i++){
            file<<0<<std::endl; //Azzera i salvataggi
        }

        file<<40<<std::endl;
        file<<0<<std::endl;
        file<<0<<std::endl;

        file.close();
    }

    else std::cerr << "Errore nell'apertura del file." << std::endl;
}