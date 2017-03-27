#pragma once
#include <SFML\Graphics.hpp>


class Bonus : public sf::Drawable, public sf::Transformable
{
private:
	sf::Sprite m_visual;
public:
	enum Fruit
	{
		Banana,
		Apple,
		Cherry
	};

private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	Bonus(sf::Texture &texture);
	~Bonus();
	void setFruit(Fruit fruit);
};

