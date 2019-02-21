#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "game_state.h"

#include <SFML/Graphics.hpp>

#include "game.h"

class MainMenuState : public GameState {
public:
	MainMenuState(Game &game);
	~MainMenuState() {}

	virtual void handleEvents(const sf::Event &event);
	virtual void update(sf::Time deltaTime);
	virtual void render();

private:
	sf::Font blockyFont, robotoFont;
	sf::Text title, pvpOption, pvcOption, quitOption;
};

#endif
