#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "game_state.h"

class Game {
public:
	Game(sf::RenderWindow &gameWindow, GameState *initialState = nullptr);

	void addState(GameState *state);
	void removeState(int index);
	void removeState(GameState *state);

	void update(sf::Time deltaTime);
	void render();
	void handleEvents();

private:
	std::vector<GameState*> gameStates;
	sf::RenderWindow &window;
};

#endif
