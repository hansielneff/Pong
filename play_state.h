#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "game_state.h"

#include "game.h"
#include "ball.h"
#include "paddle.h"

class PlayState : public GameState {
public:
	PlayState(Game &game, bool pvp);
	~PlayState() {}

	virtual void handleEvents(const sf::Event &event);
	virtual void update(sf::Time deltaTime);
	virtual void render();

private:
	void resetGame();
	void updatePlayerPositions(sf::Time deltaTime);
	void keepBallWithinBounds();

	sf::Font robotoFont;
	sf::Text scores, spaceToStart;
	Ball ball;
	Paddle p1, p2;
	sf::Uint32 p1Score = 0, p2Score = 0;

	bool gameStarted = false;
};

#endif
