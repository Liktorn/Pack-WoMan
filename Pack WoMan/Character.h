#pragma once
#include <SFML/Graphics.hpp>

class Character : public sf::Drawable, public sf::Transformable
{
public:
	Character();
	~Character();

	void setSpeed(float speed);
	float getSpeed() const;

private:
	float m_speed;
};

