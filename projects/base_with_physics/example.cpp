#include "example.h"
#include "MainMenu.h"
#include "Level1.h"

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
	// Initialise the physics system. Set the default gravity to 9.8m/s^2 down.

	//m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	//sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	//m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	sceneManager.AddScene(new MainMenu());
	sceneManager.AddScene(new Level1());

	return true;
}

void Example::update(float deltaT)
{
	// You need to update the physics system every game update


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		sceneManager.LoadScene(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		sceneManager.LoadScene(0);
	}
	sceneManager.Update();
	
	/*ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();*/
}

void Example::render()
{
	//m_window.draw(*m_backgroundSprite);
	sceneManager.Render(m_window);
	

}

void Example::cleanup()
{
	//delete m_backgroundSprite;
}

