#pragma once
#include <SFML/Graphics.hpp>

class SpriteAnimator
{
private:
	sf::Texture* brickAnimation;
	sf::Sprite BreakoutSheet;
	sf::Clock clock;
	int indexX = 0;
	int indexY = 1;
	sf::Vector2f startFrame;
	sf::Vector2f endFrame;
	int speed;
	sf::Vector2f currentFrame;
	bool startAnimation = false;

public:
	SpriteAnimator();
	~SpriteAnimator();
	void Update();
	void Render(sf::RenderWindow& window);
	void Init();
	void LoadTexture();
	void StartAnimation(sf::Vector2f startFrame, sf::Vector2f endFrame, int speed);

};

