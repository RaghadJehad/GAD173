#include "SpriteAnimator.h"
#include <kage2dutil/texture_manager.h>
#include "Grid.h"
#include <iostream>

#define BrickWidth 53
#define BrickHeight 25
using namespace sf;

SpriteAnimator::SpriteAnimator()
{
}


void SpriteAnimator::LoadTexture()
{
	blueBrick = kage::TextureManager::getTexture("data/blueblockspritesheet.png");
	BlueSprite.setTexture(*blueBrick);
	BlueSprite.setPosition(sf::Vector2f(Grid_OFFSET_X, Grid_OFFSET_Y));
	BlueSprite.setScale(sf::Vector2f(0.66, 1.4));
	BlueSprite.setTextureRect(sf::IntRect(0, 0, BrickWidth, BrickHeight));
	
	yellowBrick = kage::TextureManager::getTexture("data/yellowblockspritesheet.png");
	YellowSprite.setTexture(*yellowBrick);
	YellowSprite.setPosition(sf::Vector2f(Grid_OFFSET_X, Grid_OFFSET_Y));
	YellowSprite.setScale(sf::Vector2f(0.66, 1.4));
	YellowSprite.setTextureRect(sf::IntRect(0, 0, BrickWidth, BrickHeight));

	redBrick = kage::TextureManager::getTexture("data/redblockspritesheet.png");
	RedSprite.setTexture(*redBrick);
	RedSprite.setPosition(sf::Vector2f(Grid_OFFSET_X, Grid_OFFSET_Y));
	RedSprite.setScale(sf::Vector2f(0.66, 1.4));
	RedSprite.setTextureRect(sf::IntRect(0, 0, BrickWidth, BrickHeight));
}

void SpriteAnimator::StartAnimation(Vector2i startFrame, Vector2i endFrame, int speed)
{
	this->startFrame = startFrame; //''this'' declares the var equal to with same name
	this->endFrame = endFrame; //''->'' deref. 
	this->speed = speed; 
	startAnimation = true;
	currentFrame = startFrame;
}

void SpriteAnimator::Update()
{
	if (startAnimation)
	{
		Time timer = clock.getElapsedTime();
		
		if (timer.asMilliseconds() > speed)
		{
			int x = BrickWidth * currentFrame.x;
			int y = BrickHeight * currentFrame.y;
			
			            //displays a part of the texture
			BlueSprite.setTextureRect(sf::IntRect(x, y, BrickWidth, BrickHeight));
			YellowSprite.setTextureRect(sf::IntRect(x, y, BrickWidth, BrickHeight));
			RedSprite.setTextureRect(sf::IntRect(x, y, BrickWidth, BrickHeight));
			currentFrame.x++; //every frame it increments by 1

			if (currentFrame.x >= endFrame.x) 
			{
				currentFrame = startFrame;
			}
			clock.restart();
		}
	}
}


void SpriteAnimator::Render(sf::RenderWindow& window)
{
	if (startAnimation) 
	{
		//draws each sprite ID
		if (chosenTileID == 1) {
			window.draw(BlueSprite);
		}
		if (chosenTileID == 2) {
			window.draw(RedSprite);
		}
		if (chosenTileID == 3) {
			window.draw(YellowSprite);
		}
		
	}	
}

SpriteAnimator::~SpriteAnimator()
{
}