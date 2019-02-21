#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SFML/Graphics.hpp"

class Game;

class GameState {
public:
	GameState(Game &game) : game { game } {}
	virtual ~GameState() {};

	virtual void handleEvents(const sf::Event &event) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render() = 0;

protected:
	Game &game;
};

#endif
