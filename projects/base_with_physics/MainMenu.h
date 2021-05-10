#pragma once
#include "Scene.h"

class MainMenu : Scene //inhereting from scene
{
public: 
	MainMenu();
	~MainMenu();

	void Load() override;
	void Init() override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;
};

