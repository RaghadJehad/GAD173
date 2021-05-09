#pragma once
#include <SFML/Graphics.hpp>

class SpriteAnimator
{
private:
	sf::Texture* brickAnimation;
	sf::Sprite BreakoutSheet;
	sf::Clock clock;
	
	sf::Vector2i startFrame; //vector2i for int
	sf::Vector2i endFrame;
	int speed;
	sf::Vector2i currentFrame;
	bool startAnimation = false;

public:
	SpriteAnimator();
	~SpriteAnimator();
	void Update();
	void Render(sf::RenderWindow& window);
	void Init();
	void LoadTexture();
	void StartAnimation(sf::Vector2i startFrame, sf::Vector2i endFrame, int speed);

};

