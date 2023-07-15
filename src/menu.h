#ifndef DOODLE_JUMP_MENU_H
#define DOODLE_JUMP_MENU_H
#include <string>
#include "assets.h"
#include "platform.h"

void formattingText(Text &text, int sizeText, Vector2f positionText, std::string content) {
	text.setFont(fontGame);
	text.setCharacterSize(sizeText);
	text.setPosition(positionText);
	text.setFillColor(Color::Black);
	text.setString(content);
}

void startMenu(RenderWindow &window) {
	Text globalText;
	Text startText;
	formattingText(*&startText, 35, Vector2f(120, 350), "Press Space to start");
	formattingText(*&globalText, 80, Vector2f(85, 250), "Doodle Jump");
	
	player.setPosition(Vector2f(210, 120));

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Space) {
					return;
				}
			}
		}
		window.draw(background);
		window.draw(player);
		window.draw(startText);
		window.draw(globalText);
		window.display();
	}
}

void endMenu(RenderWindow &window, Text scoreText) {
	Text endText;
	Text recordText;
	Text restartText;
	formattingText(*&endText, 80, Vector2f(110, 150), "GameOver!");
	formattingText(*&recordText, 40, Vector2f(120, 250), "Your record:");
	formattingText(*&restartText, 40, Vector2f(120, 400), "Press R to restart");
	scoreText.setPosition(320, 250);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::R) {
					return;
				}
			}
		}

		window.clear();
		window.draw(background);
		window.draw(endText);
		window.draw(recordText);
		window.draw(restartText);
		window.draw(scoreText);
		window.display();
	}
}

#endif