#include "Map.h"
using namespace std;

Map::Map() 
{
	redBlock.setTexture(*blockRTexture);
	redBlock.setPosition(sf::Vector2f(100, 35));
}

Map::~Map() 
{

}