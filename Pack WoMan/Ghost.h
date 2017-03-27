#pragma once
#include "Character.h"
#include "PacWoman.h"
#include "Animator.h"

class Ghost : public Character
{
public:

	enum State
	{
		Strong,
		Weak
	};

public:
	Ghost(sf::Texture& texture);
	~Ghost();
	void setWeak(sf::Time duration);
	bool isWeak() const;

	void update(sf::Time delta);


private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool m_isWeak;
	sf::Time m_weaknessDuration;

	sf::Sprite m_visual;
	PacWoman* m_pacWoman;

	Animator m_strongAnimator;
	Animator m_weakAnimator;

};

