#include "play_state.h"

#include "util.h"

PlayState::PlayState(Game &game, bool pvp) 
: GameState(game)
, ball(game.window.getSize().x / 2, game.window.getSize().y / 2, 8)
, p1(50, game.window.getSize().y / 2)
, p2(game.window.getSize().x - 50, game.window.getSize().y / 2) {
	robotoFont.loadFromFile("res/fonts/Roboto/Roboto-Light.ttf");
	Util::initializeText(scores, "0 - 0", robotoFont, 50, game.window.getSize().x / 2, 25);
	Util::initializeText(spaceToStart, "Press SPACE to start", robotoFont, 25, 
		game.window.getSize().x / 2, game.window.getSize().y - 50);
}

void PlayState::handleEvents(const sf::Event &event) {
	switch (event.type) {
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Space && !gameStarted) {
			gameStarted = true;
			ball.travelRandomDirection();
		}
	}
}

void PlayState::update(sf::Time deltaTime) {
	updatePlayerPositions(deltaTime);
	ball.update(deltaTime);
	keepBallWithinBounds();


}

void PlayState::render() {
	game.window.draw(ball);
	game.window.draw(p1);
	game.window.draw(p2);
	game.window.draw(scores);
	if (!gameStarted) game.window.draw(spaceToStart);
}

void PlayState::resetGame() {
	gameStarted = false;
	ball.stopMoving();
	ball.setPosition(game.window.getSize().x / 2, 
		game.window.getSize().y / 2);
	p1Score = p2Score = 0;
}

void PlayState::updatePlayerPositions(sf::Time deltaTime) {
	// Player 1
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
		p1.getPosition().y - p1.getSize().y / 2 > 0)
		p1.move(0, -p1.getMoveSpeed() * deltaTime.asSeconds());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		p1.getPosition().y + p1.getSize().y / 2 < game.window.getSize().y)
		p1.move(0, p1.getMoveSpeed() * deltaTime.asSeconds());

	// Player 2
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		p2.getPosition().y - p2.getSize().y / 2 > 0)
		p2.move(0, -p2.getMoveSpeed() * deltaTime.asSeconds());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		p2.getPosition().y + p2.getSize().y / 2 < game.window.getSize().y)
		p2.move(0, p2.getMoveSpeed() * deltaTime.asSeconds());
}

void PlayState::keepBallWithinBounds() {
	if (ball.getPosition().x < 0) ball.setTravelDirection(
		sf::Vector2f(abs(ball.getTravelDirection().x), ball.getTravelDirection().y));

	if (ball.getPosition().x > game.window.getSize().x) ball.setTravelDirection(
		sf::Vector2f(-abs(ball.getTravelDirection().x), ball.getTravelDirection().y));

	if (ball.getPosition().y < 0) {
		ball.setTravelDirection(sf::Vector2f(ball.getTravelDirection().x, 
			abs(ball.getTravelDirection().y)));
		p2Score++;
	}

	if (ball.getPosition().y > game.window.getSize().y) {
		ball.setTravelDirection(sf::Vector2f(ball.getTravelDirection().x,
			-abs(ball.getTravelDirection().y)));
		p1Score++;
	}
}