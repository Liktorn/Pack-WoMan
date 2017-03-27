#include "Character.h"



Character::Character()
	:m_speed(1.f)
{
}


Character::~Character()
{
}

void Character::setSpeed(float speed)
{
	m_speed = speed;
}
float Character::getSpeed() const
{
	return m_speed;
}
