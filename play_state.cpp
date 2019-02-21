#include "play_state.h"

#include "util.h"

PlayState::PlayState(Game &game, bool pvp) : GameState(game) {
	robotoFont.loadFromFile("res/fonts/Roboto/Roboto-Light.ttf");
	Util::initializeText(scores, "0 - 0", robotoFont, 50, 
		game.getWindow().getSize().x / 2, 25);

	ball.setRadius(10);
	ball.setOrigin(ball.getRadius() / 2, ball.getRadius() / 2);
	ball.setPosition(game.getWindow().getSize().x / 2, 
		game.getWindow().getSize().y / 2);

	p1.setSize(sf::Vector2f(20, 100));
	p1.setOrigin(p1.getSize().x / 2, p1.getSize().y / 2);
	p1.setPosition(50, game.getWindow().getSize().y / 2);

	p2.setSize(sf::Vector2f(20, 100));
	p2.setOrigin(p2.getSize().x / 2, p2.getSize().y / 2);
	p2.setPosition(game.getWindow().getSize().x - 50, 
		game.getWindow().getSize().y / 2);
}

PlayState::~PlayState() {

}

void PlayState::handleEvents(const sf::Event &event) {

}

void PlayState::update(sf::Time deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		p1.move(0, -playerMoveSpeed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		p1.move(0, playerMoveSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		p2.move(0, -playerMoveSpeed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		p2.move(0, playerMoveSpeed);
}

void PlayState::render() {
	game.getWindow().draw(ball);
	game.getWindow().draw(p1);
	game.getWindow().draw(p2);
	game.getWindow().draw(scores);
}