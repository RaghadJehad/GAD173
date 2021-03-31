#include "Grid.h"

using namespace std;


 Grid::Grid()
{
	 for (size_t i = 0; i < 21; i++)
	 {
		 lineH[i].setSize(sf::Vector2f(700, 1));
		 lineH[i].setPosition(sf::Vector2f(0, 0 + i *Y_Spacing));
		 
	 }
	 for (size_t i = 0; i < 21; i++)
	 {
		 lineV[i].setSize(sf::Vector2f(1, 700));
		 lineV[i].setPosition(sf::Vector2f(0 + i * X_Spacing, 0));
	 }
}

Grid::~Grid()
{
}

void Grid::Render(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 21; i++)
	{
		window.draw(lineH[i]);
		window.draw(lineV[i]);
	}
}