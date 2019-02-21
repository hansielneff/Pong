#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "game_state.h"

class Game {
public:
	Game(sf::RenderWindow &gameWindow) : window{ gameWindow } {}

	void addState(GameState *state);
	void removeState(int index);
	void removeState(GameState *state);

	void update(sf::Time deltaTime);
	void render();
	void handleEvents();

	sf::RenderWindow& getWindow() { return window; }

private:
	std::vector<GameState*> gameStates;
	sf::RenderWindow &window;
};

#endif
