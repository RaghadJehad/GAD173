#include "Grid.h"

using namespace std;


 Grid::Grid()
{
	 for (size_t i = 0; i < H_ARRAY; i++)
	 {
		 lineH[i].setSize(sf::Vector2f(H_Lines_X, H_Lines_Y));
		 lineH[i].setPosition(sf::Vector2f(Grid_OFFSET_X, Grid_OFFSET_Y + i *Cell_Height));
		 
	 }
	 for (size_t i = 0; i < V_ARRAY; i++)
	 {
		 lineV[i].setSize(sf::Vector2f(V_Lines_X, V_Lines_Y));
		 lineV[i].setPosition(sf::Vector2f(Grid_OFFSET_X + i *Cell_Width, Grid_OFFSET_Y));
	 }
}

Grid::~Grid()
{
}

void Grid::Render(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 22; i++)
	{
		window.draw(lineH[i]);
		window.draw(lineV[i]);
	}
}