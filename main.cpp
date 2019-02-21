#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "game.h"
#include "main_menu_state.h"

int main() {
	/*std::vector<sf::VideoMode> validResolutions = sf::VideoMode::getFullscreenModes();
	sf::RenderWindow window(validResolutions.front(), "Pong", sf::Style::Fullscreen);*/
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong", sf::Style::Default, settings);
	sf::Image icon;
	icon.loadFromFile("res/icon.png");
	window.setIcon(250, 250, icon.getPixelsPtr());
	window.setFramerateLimit(60);
	Game game(window);
	game.addState(new MainMenuState(game));
	sf::Clock clock;

	std::srand(std::time(nullptr));

	while (window.isOpen()) {
		game.handleEvents();
		game.update(clock.restart());
		game.render();
	}
}