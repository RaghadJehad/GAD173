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
	/*blockRTexture = kage::TextureManager::getTexture("data/red.png");
	blockBTexture = kage::TextureManager::getTexture("data/blue.png");
	blockGTexture = kage::TextureManager::getTexture("data/green.png");*/

	for (size_t y = 0; y < Total_Y_CELLS; y++)
	{
		for (size_t x = 0; x < Total_X_CELLS; x++)
		{
			int i = x + y * (Total_X_CELLS);
			
			if (map[i] == 1)
			{
				tile[i].chosenTileID = 1;
				tile[i].BlueSprite.setPosition(sf::Vector2f(Grid_OFFSET_X + x * Cell_Width,
					Grid_OFFSET_Y + y * Cell_Height));
				
				//tile[i].LoadTexture();
				//tiles[i].setTexture(*blockRTexture);
			}
			if (map[i] == 2)
			{
				tile[i].chosenTileID = 2;
				tile[i].RedSprite.setPosition(sf::Vector2f(Grid_OFFSET_X + x * Cell_Width,
					Grid_OFFSET_Y + y * Cell_Height));
			}
			
			if (map[i] == 3)
			{
				tile[i].chosenTileID = 3;
				tile[i].YellowSprite.setPosition(sf::Vector2f(Grid_OFFSET_X + x * Cell_Width,
					Grid_OFFSET_Y + y * Cell_Height));
			}
			tile[i].StartAnimation(sf::Vector2i(0, 1), sf::Vector2i(6, 0), 120);
		}
	}
}

void Map::Update()
{
	for (size_t i = 0; i < Map_Size; i++)
	{
		tile[i].Update();
	}
}

void Map::Render(sf::RenderWindow& m_window)
{
	for (size_t i = 0; i < Map_Size; i++)
	{
		tile[i].Render(m_window);
	}
} 

Map::~Map() 
{
}