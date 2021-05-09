#include "example.h"
#include <string>

using namespace std;

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	map.Load();
	animator.Init();
	animator.LoadTexture();
	/*string line = "GAME OVER MUSTAFA HAHA xD !!!!!";
	string numStr1 = line.substr(0, 4);
	string numStr2 = line.substr(5, 4);
	string numStr3 = line.substr(10, 7);
	string numStr5 = line.substr(18, 4);
	string numStr6 = line.substr(23, 2);
	string numStr7 = line.substr(26, 5);

	std::cout << numStr1 << std::endl;
	std::cout << numStr2 << std::endl;
	std::cout << numStr3 << std::endl;
	std::cout << numStr5 << std::endl;
	std::cout << numStr6 << std::endl;
	std::cout << numStr7 << std::endl;
	*/

	return true;
}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	if (ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	if(ImGui::ImageButton(*map.blockRTexture, sf::Vector2f(35,35)))
	{
		map.chosenTileID = 1;
	}
	if (ImGui::ImageButton(*map.blockBTexture, sf::Vector2f(35, 35)))
	{
		map.chosenTileID = 2;
	}
	if (ImGui::ImageButton(*map.blockGTexture, sf::Vector2f(35, 35)))
	{
		map.chosenTileID = 3;
	}
	if (ImGui::Button("Save"))
	{  
		SaveLoad::Save("map.txt", map.map, 21, 21);
	}
	if(ImGui::Button("Load"))
	{
		SaveLoad::Load("map.txt", Map_Size, map);
		map.Load();
	}
	ImGui::End();


	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
		mousePosition.x >= 0 && mousePosition.x <= X_Lines * Cell_Width &&
		mousePosition.y >= 0 && mousePosition.y <= Y_Lines * Cell_Height)
	{
		int mouseOnCellX = (mousePosition.x - Grid_OFFSET_X) / Cell_Width;
		int mouseOnCellY = (mousePosition.y - Grid_OFFSET_Y) / Cell_Height;
		int i = mouseOnCellX + mouseOnCellY * 21;

		if (map.chosenTileID == 1) 
		{
			map.tiles[i].setTexture(*map.blockRTexture);
			map.map[i] = 1;
		}
		if (map.chosenTileID == 2)
		{
			map.tiles[i].setTexture(*map.blockBTexture);
			map.map[i] = 2;
		}
		if (map.chosenTileID == 3)
		{
			map.tiles[i].setTexture(*map.blockGTexture);
			map.map[i] = 3;
		}
	
		std::cout << mouseOnCellX << " " << mouseOnCellY << std::endl;
	}
	animator.Update();
}
	

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	grid.Render(m_window);
	animator.Render(m_window);
	for (size_t i = 0; i < Map_Size; i++)
	{
		m_window.draw(map.tiles[i]);
	}
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

