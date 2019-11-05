#include "ball.h"
#include "Game.h"
#include "Util.h"
#include "GLM/gtx/rotate_vector.hpp"
#include "PlayScene.h"
#include "GLM/gtx/string_cast.hpp"


Ball::Ball()
{
	TheTextureManager::Instance()->load("../Assets/textures/planet.png","ball", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("ball");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0.0f, 0.0f));
	setInitialPosition(getPosition());

	setVelocity(glm::vec2(0.0f, 0.0f));
	setInitialVelocity(getVelocity());
	setAcceleration(glm::vec2(0.0f, 0.0f));

	setIsColliding(false);
	setType(GameObjectType::BALL);
	setState(State::IDLE);

	m_fMass = 0.f;
}


Ball::~Ball()
{
}

void Ball::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	int Width = getWidth();
	int Height = getHeight();

	TheTextureManager::Instance()->draw("ball", xComponent - (Width * 0.5f), yComponent - (Height * 0.5f),
		TheGame::Instance()->getRenderer(), 0.f, 255);
}

void Ball::update()
{
	//move();
	//getParent()->
}

void Ball::clean()
{
	
}

//void Ball::move()
//{
//	if (Util::distance(getPosition(), m_target) > 1.0f) {
//		glm::vec2 desired = Util::normalize(m_target - getPosition()) * m_maxSpeed;
//		setVelocity(desired);
//
//
//		glm::vec2 newPosition = getPosition() + getVelocity();
//		setPosition(newPosition);
//	}
//
//
//}

//void Ship::m_checkBounds()
//{
//
//	if (getPosition().x > Config::SCREEN_WIDTH)
//	{
//		setPosition(glm::vec2(0.0f, getPosition().y));
//	}
//
//	if (getPosition().x < 0)
//	{
//		setPosition(glm::vec2(800.0f, getPosition().y));
//	}
//
//	if (getPosition().y > Config::SCREEN_HEIGHT)
//	{
//		setPosition(glm::vec2(getPosition().x, 0.0f));
//	}
//
//	if (getPosition().y < 0)
//	{
//		setPosition(glm::vec2(getPosition().x, 600.0f));
//	}
//}

void Ball::Reset()
{
	setPosition(getInitialPosition());
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));

	m_fMass = 0.f;

	setIsColliding(false);
}