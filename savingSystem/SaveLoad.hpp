#pragma once
#include <fstream>
#include <iostream>
#include"../class/map/room.hpp"
#include "../class/objects.hpp"

void saveGame (objects* obj_info, room* room_info);
void loadGame (objects* obj_info, room* room_info);
void deleteSave ();