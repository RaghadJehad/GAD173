#pragma once
#include <SFML/Graphics.hpp>

class SpriteAnimator
{
private:
	sf::Texture* blueBrick;
	sf::Texture* yellowBrick;
	sf::Texture* redBrick;
	sf::Clock clock;
	sf::Vector2i startFrame; //vector2i for int
	sf::Vector2i endFrame;
	int speed;
	sf::Vector2i currentFrame;
	bool startAnimation = false;

public:
	sf::Sprite BlueSprite;
	sf::Sprite YellowSprite;
	sf::Sprite RedSprite;
	int chosenTileID = 0;
	SpriteAnimator();
	~SpriteAnimator();
	void Update();
	void Render(sf::RenderWindow& window);
	void LoadTexture();
	void StartAnimation(sf::Vector2i startFrame, sf::Vector2i endFrame, int speed);
	
};

