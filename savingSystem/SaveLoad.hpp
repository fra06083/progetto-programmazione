#pragma once
#include <fstream>
#include <iostream>
#include"../class/personaggio.hpp"
#include "../class/objects.hpp"

void saveGame (objects* obj_info, Player* player_info);
void loadGame (objects* obj_info, Player* player_info);
void deleteSave ();