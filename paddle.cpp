#include "paddle.h"

Paddle::Paddle(float x, float y, float width, float height) {
	setOrigin(width / 2, height / 2);
	setPosition(x, y);
	setSize(sf::Vector2f(width, height));
}