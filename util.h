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
}

#endif
