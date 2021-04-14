#pragma once
#include <SFML/Graphics.hpp>

#define Total_X_CELLS 21
#define Total_Y_CELLS 21
#define Cell_Height 35
#define	Cell_Width 35
#define Grid_OFFSET_X 50
#define Grid_OFFSET_Y 100
#define H_ARRAY 22
#define V_ARRAY 22

//POSITION OF THE LINES
#define H_Lines_X Total_X_CELLS * Cell_Width
#define H_Lines_Y 1

#define V_Lines_X 1
#define V_Lines_Y Total_Y_CELLS * Cell_Height

class Grid
{
public:
	Grid();
	~Grid();
	
	void Render(sf::RenderWindow& window);
	sf::RectangleShape lineH[H_ARRAY];
	sf::RectangleShape lineV[V_ARRAY];
};

