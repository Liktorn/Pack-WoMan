#pragma once
#include "Character.h"
#include "PacWoman.h"
#include "Animator.h"

class Ghost : public Character
{
private:
	sf::Sprite m_visual;
	bool m_isWeak;
	sf::Time m_weaknessDuration;
	PacWoman *m_pacWoman;
	Animator m_strongAnimator;
	Animator m_weakAnimator;

public:
	enum State
	{
		Strong,
		Weak
	};
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	Ghost(sf::Texture &texture, PacWoman *pacWoman);
	~Ghost();
	void setWeak(sf::Time duration);
	bool isWeak() const;
	void update(sf::Time delta);

};

