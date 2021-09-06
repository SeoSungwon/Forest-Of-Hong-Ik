
#pragma once

#include "GetGameMapManager.hpp"

class GameMap {
public:
	GetGameMapManager* gameMapManager;

	GameMap() : gameMapManager(nullptr) {} 
	~GameMap() { }
};