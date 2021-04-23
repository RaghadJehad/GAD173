#pragma once
#include <iostream>
#include "Map.h"

class SaveLoad
{
public:

	static void Save(std::string filename, int* buffer, int X_COUNT, int Y_COUNT);
	static void Load(std::string filename, int mapArraySize, Map& map);
};

