#pragma once
#include "Animator.h"
#include "Character.h"

class PacWoman : public Character
{
public:
	void die();
	bool isDying() const;
	bool isDead() const;


private:

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
	bool m_isDead;
	bool m_isDying;
	sf::Sprite m_visual;
	Animator m_runAnimator;
	Animator m_dieAnimator;

public:
	PacWoman(sf::Texture &texture);
	~PacWoman();
	void update(sf::Time delta);
	
	
};

