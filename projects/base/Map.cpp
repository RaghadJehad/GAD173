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

	for (size_t y = 0; y < Total_Y_CELLS; y++)
	{
		for (size_t x = 0; x < Total_X_CELLS; x++)
		{
			int i = x + y * (Total_X_CELLS);

			if (map[i] == 1)
			{
				tiles[i].setTexture(*blockRTexture);
				//tiles[i].setColor(sf::Color(255, 255, 255, 255));
			}
			if (map[i] == 2)
			{
				tiles[i].setTexture(*blockBTexture);
				//tiles[i].setColor(sf::Color(255, 255, 255, 255));
			}
			if (map[i] == 3)
			{
				tiles[i].setTexture(*blockGTexture);
				//tiles[i].setColor(sf::Color(255, 255, 255, 255));
			}
			tiles[i].setPosition(sf::Vector2f(Grid_OFFSET_X + x * Cell_Width,
				Grid_OFFSET_Y + y * Cell_Height));
		}
	}
}

/*void Map::Render(sf::RenderWindow& window)
{
		window.draw(tiles);
}*/ 

Map::~Map() 
{
}