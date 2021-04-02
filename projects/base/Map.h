#pragma once
#include <SFML/Graphics.hpp>

#define X_Lines 21
#define Y_Lines 7

class Map
{
public:
	Map();
	~Map();
	void Load();
	
	sf::Texture* blockRTexture;
	sf::Texture* blockBTexture;
	sf::Texture* blockGTexture;
	sf::Sprite redBlock;
	sf::Sprite blueBlock;
	sf::Sprite greenBlock;
	
	sf::Sprite tiles[147];

	int map[147] = {
		1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 2, 2, 2, 0, 2, 2, 2,
		1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 2, 2, 2, 0, 2, 2, 2,
		1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 2, 2, 2, 0, 2, 2, 2,
		1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 2, 2, 2, 0, 2, 2, 2,
		1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 2, 2, 2, 0, 2, 2, 2,
		1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 2, 2, 2, 0, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	//void Render(sf::RenderWindow& window);
};

