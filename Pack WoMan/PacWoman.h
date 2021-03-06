#pragma once
#include "Animator.h"
#include "Character.h"

class PacWoman : public Character
{
public:
	PacWoman(sf::Texture& texture);
	void die();

	bool isDying() const;
	bool isDead() const;

	void update(sf::Time delta);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool m_isDying;
	bool m_isDead;
	sf::Sprite m_visual;

	Animator m_runAnimator;
	Animator m_dieAnimator;
	
	
};

