#pragma once
#include <SFML/Graphics.hpp>

#define Cell_Height 35
#define	Cell_Width 35
#define Grid_OFFSET_X 50
#define Grid_OFFSET_Y 100

class Grid
{
public:
	Grid();
	~Grid();
	
	void Render(sf::RenderWindow& window);
	sf::RectangleShape lineH[21];
	sf::RectangleShape lineV[21];
};

