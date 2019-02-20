#include "main_menu_state.h"

MainMenuState::MainMenuState(sf::RenderWindow &gameWindow) : GameState(gameWindow) {
	title.setString("PONG");
}

MainMenuState::~MainMenuState() {}

void MainMenuState::handleEvents(const sf::Event &event) {
	
}

void MainMenuState::update(sf::Time deltaTime) {

}

void MainMenuState::render() {
	window.draw(title);
}