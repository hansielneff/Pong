#include "game.h"

void Game::addState(GameState *state) {
	gameStates.push_back(state);
}

void Game::removeState(int index) {
	if (index + 1 <= gameStates.size()) {
		delete gameStates[index];
		gameStates.erase(gameStates.begin() + index);
	}
}

void Game::removeState(GameState *state) {
	for (std::vector<GameState*>::size_type i = 0; i < gameStates.size(); i++)
		if (gameStates[i] == state) removeState(i);
}

void Game::update(sf::Time deltaTime) {
	if (!gameStates.empty()) gameStates.back()->update(deltaTime);
}

void Game::render() {
	window.clear();
	if (!gameStates.empty()) gameStates.back()->render();
	window.display();
}

void Game::handleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (!gameStates.empty()) gameStates.back()->handleEvents(event);

		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window.close();
		}
	}
}