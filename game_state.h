#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SFML/Graphics.hpp"

class GameState {
public:
	GameState(sf::RenderWindow &gameWindow) : window { gameWindow } {}
	virtual ~GameState() {};

	virtual void handleEvents(const sf::Event &event) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render() = 0;

protected:
	sf::RenderWindow &window;
};

#endif
