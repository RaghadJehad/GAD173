#pragma once
#include "Scene.h"

class MainMenu : public Scene //inhereting from scene for menu to become a scene 
								//to add it to the list of scenes
{
public: 
	MainMenu();
	~MainMenu();

	void Load() override;
	void Init() override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;
};

