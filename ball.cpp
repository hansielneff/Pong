#include "ball.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

Ball::Ball(float x, float y, float radius) {
	setOrigin(radius / 2, radius / 2);
	setPosition(x, y);
	setRadius(radius);
}

void Ball::update(sf::Time deltaTime) {
	move(travelDir.x * moveSpeed * deltaTime.asSeconds(), 
		travelDir.y * moveSpeed * deltaTime.asSeconds());
}

void Ball::travelRandomDirection() {
	int direction = std::rand() / ((RAND_MAX + 1) / 4);

	switch (direction) {
		case 0: setTravelDirection(sf::Vector2f(1, 1)); break;
		case 1: setTravelDirection(sf::Vector2f(-1, 1)); break;
		case 2: setTravelDirection(sf::Vector2f(1, -1)); break;
		case 3: setTravelDirection(sf::Vector2f(-1, -1)); break;
	}
}
