#ifndef UTIL_H
#define UTIL_H

namespace Util {
	static void initializeText(sf::Text &text, const sf::String &content, 
		const sf::Font &font, float charSize, float x, float y) {
		text.setString(content);
		text.setFont(font);
		text.setCharacterSize(charSize);
		text.setOrigin(text.getGlobalBounds().width / 2,
			text.getGlobalBounds().height / 2);
		text.setPosition(x, y);
	}

	static float vectorMagnitude(const sf::Vector2f &vec) {
		return sqrtf(vec.x * vec.x + vec.y * vec.y);
	}

	static sf::Vector2f normalizedVector(const sf::Vector2f &vec) {
		return vec / vectorMagnitude(vec);
	}
}

#endif
