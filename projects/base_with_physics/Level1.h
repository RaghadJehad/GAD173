#pragma once
#include "Scene.h"

class Level1 : public Scene
{
public:
	Level1();
	~Level1();

	void Load() override;
	void Init() override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;
};

