#pragma once
#include <SFML/Graphics.hpp>

#define Y_Spacing 35
#define	X_Spacing 35

class Grid
{
public:
	Grid();
	~Grid();
	
	void Render(sf::RenderWindow& window);
	sf::RectangleShape lineH[21];
	sf::RectangleShape lineV[21];
};

