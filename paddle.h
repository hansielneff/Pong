#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape {
public:
	Paddle(float x, float y, float width = 20, float height = 100);
	~Paddle() {}

	float getMoveSpeed() const { return moveSpeed; }
	void setMoveSpeed(float speed) { moveSpeed = speed; }

private:
	float moveSpeed = 400;
};

#endif
