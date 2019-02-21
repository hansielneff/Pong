#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "game_state.h"

#include "game.h"

class PlayState : public GameState {
public:
	PlayState(Game &game, bool pvp);
	~PlayState();

	virtual void handleEvents(const sf::Event &event);
	virtual void update(sf::Time deltaTime);
	virtual void render();

private:
	sf::Font robotoFont;
	sf::Text scores;

	sf::CircleShape ball;
	sf::RectangleShape p1, p2;
	sf::Uint32 p1Score = 0, p2Score = 0;

	const float playerMoveSpeed = 10;
};

#endif
