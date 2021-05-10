#pragma once
#include "Grid.h"
#include "app.h"
#include "Map.h"
#include "SaveLoad.h"
#include "SpriteAnimator.h"

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	sf::Sprite* m_backgroundSprite = nullptr;
	Map map;
	Grid grid;
	SpriteAnimator animator;
};
