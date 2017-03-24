#pragma once
#include "GameState.h"
#include <SFML\Graphics.hpp>
#include <array>


class Game
{
private:
	sf::RenderWindow m_window;
	// Pointer pointing to the current state
	GameState* m_currentState;
	std::array<GameState*, GameState::Count> m_gameStates;

	sf::Font m_font;
	sf::Texture m_logo;
	sf::Texture m_texture;

public:
	Game();
	~Game();

	void run();

	sf::Font& getFont();
	sf::Texture& getLogo();
	sf::Texture& getTexture();

	void changeGameState(GameState::State gameState);

};


