#ifndef COLLISION_H
#define COLLISION_H

#include "base_enemy.hpp"
#include "medium_enemy.hpp"
#include "tough_enemy.hpp"
bool Base_isPositionOccupied(int x, int y, p_base_en base_en);
bool Medium_isPositionOccupied(int x, int y, p_medium_en medium_en);
bool Tough_isPositionOccupied(int x, int y, p_tough_en tough_en);

#endif