#include "SpriteAnimator.h"
#include <kage2dutil/texture_manager.h>
#include "Grid.h"
#define BrickWidth 53
#define BrickHeight 25
using namespace sf;

SpriteAnimator::SpriteAnimator()
{
}
void SpriteAnimator::Init()
{
}

void SpriteAnimator::LoadTexture()
{

	
	brickAnimation = kage::TextureManager::getTexture("data/blueblockspritesheet.png");
	BreakoutSheet.setTexture(*brickAnimation);
	BreakoutSheet.setPosition(sf::Vector2f(Grid_OFFSET_X, Grid_OFFSET_Y));
	BreakoutSheet.setScale(sf::Vector2f(0.66, 1.4));
	BreakoutSheet.setTextureRect(sf::IntRect(0, 0, BrickWidth, BrickHeight));
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

			BreakoutSheet.setTextureRect(sf::IntRect(x, y, BrickWidth, BrickHeight));
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
	window.draw(BreakoutSheet);
}

SpriteAnimator::~SpriteAnimator()
{
}