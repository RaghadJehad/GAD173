#include "Map.h"
#include "Grid.h"
#include <kage2dutil/texture_manager.h>
#include <iostream>

using namespace std;

Map::Map() 
{
	
}

void Map::Load() 
{
	blockRTexture = kage::TextureManager::getTexture("data/red.png");
	blockBTexture = kage::TextureManager::getTexture("data/blue.png");
	blockGTexture = kage::TextureManager::getTexture("data/green.png");
	
	
	for (size_t y = 0; y < Y_Lines - 1; y++)
	{
		for (size_t x = 0; x < X_Lines - 1; x++)
		{
			int i = x + y * (X_Lines - 1);

		if (map[i] == 0)
		{
			//tiles[i].setTexture(*blockRTexture);
		}
		if (map[i] == 1)
		{
			//tiles[i].setTexture(*blockBTexture);
		}
		if (map[i] == 2) 
		{
			//tiles[i].setTexture(*blockGTexture);
			
		}
		tiles[i].setPosition(sf::Vector2f(Grid_OFFSET_X + x * Cell_Width, 
			Grid_OFFSET_Y + y * Cell_Height));
		}
		
		std::cout << "\n";
	}
	
}

Map::~Map() 
{

}