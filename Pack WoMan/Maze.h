#pragma once
#include <SFML/Graphics.hpp>
#include<array>

class Maze : public sf::Drawable
{
public:
	void loadLevel(std::string name);
	sf::Vector2i getPacWomanPosition() const;
	std::vector<sf::Vector2i> getGhostPositions() const;

	inline std::size_t positionToIndex(sf::Vector2i position) const;
	inline sf::Vector2i indexToPosition(std::size_t index) const;

private:

	enum CellData
	{
		Empty,
		Wall,
		Dot,
		SuperDot,
		Bonus
	};
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::Vector2i m_mazeSize;
	std::vector<CellData> m_mazeData;
	sf::Vector2i m_pacWomanPosition;
	std::vector<sf::Vector2i> m_ghostPositions;

	sf::RenderTexture m_renderTexture;

public:
	Maze();
	~Maze();
};

