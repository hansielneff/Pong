#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "game.h"
#include "main_menu_state.h"

int main() {
	/*std::vector<sf::VideoMode> validResolutions = sf::VideoMode::getFullscreenModes();
	sf::RenderWindow window(validResolutions.front(), "Pong", sf::Style::Fullscreen);*/
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
	window.setFramerateLimit(60);
	Game game(window, new MainMenuState(window));
	sf::Clock clock;

	while (window.isOpen()) {
		game.handleEvents();
		game.update(clock.restart());
		game.render();
	}
}