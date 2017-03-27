#include "Character.h"



Character::Character()
	: m_maze(nullptr)
	, m_speed(1.f)
	, m_currentDirection(1, 0)
	, m_nextDirection(0, 0)
{
}


Character::~Character()
{
}

void Character::setMaze(Maze *maze)
{
	m_maze = maze;
}
void Character::setSpeed(float speed)
{
	m_speed = speed;
}
float Character::getSpeed() const
{
	return m_speed;
}

void Character::update(sf::Time delta)
{
	//m_currentDirection = m_nextDirection;
}

void Character::setDirection(sf::Vector2i direction)
{
	m_nextDirection = direction;
}
sf::Vector2i Character::getDirection()
{
	return m_currentDirection;
}