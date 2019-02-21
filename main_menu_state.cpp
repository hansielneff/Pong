#include "main_menu_state.h"

#include <iostream>

#include "play_state.h"
#include "util.h"

MainMenuState::MainMenuState(Game &game) : GameState(game) {
	blockyFont.loadFromFile("res/fonts/Blocky/BlockyLettersInverted.ttf");
	robotoFont.loadFromFile("res/fonts/Roboto/Roboto-Light.ttf");
	
	Util::initializeText(title, "PONG", blockyFont, 100, game.window.getSize().x / 2, 100);
	Util::initializeText(pvpOption, "Player vs. Player", robotoFont, 30, game.window.getSize().x / 2, 250);
	Util::initializeText(pvcOption, "Player vs. Computer", robotoFont, 30, game.window.getSize().x / 2, 325);
	Util::initializeText(quitOption, "Quit", robotoFont, 30, game.window.getSize().x / 2, 400);
}

void MainMenuState::handleEvents(const sf::Event &event) {
	switch (event.type) {
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (pvpOption.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				game.addState(new PlayState(game, true));
			if (pvcOption.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				game.addState(new PlayState(game, false));
			if (quitOption.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				game.window.close();
		}
	}
}

void MainMenuState::update(sf::Time deltaTime) {

}

void MainMenuState::render() {
	game.window.draw(title);
	game.window.draw(pvpOption);
	game.window.draw(pvcOption);
	game.window.draw(quitOption);
}