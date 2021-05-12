#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Scene
{
private:
	bool isRunning; //checking if the scene is running or not
public:
	Scene();
	~Scene();
	
	virtual void Load();
	virtual void Init();
	virtual void Update();
	virtual void Render(sf::RenderWindow& window);
};

