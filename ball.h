#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "util.h"

class Ball : public sf::CircleShape {
public:
	Ball(float x, float y, float radius);
	~Ball() {}

	void update(sf::Time deltaTime);
	void travelRandomDirection();
	void stopMoving() { travelDir = sf::Vector2f(0, 0); }
	sf::Vector2f getTravelDirection() { return travelDir; }
	void setTravelDirection(sf::Vector2f direction) { travelDir = Util::normalizedVector(direction); }

private:
	sf::Vector2f travelDir;
	float moveSpeed = 500;
};

#endif
