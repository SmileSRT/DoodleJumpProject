#ifndef DOODLE_JUMP_ASSETS_H
#define DOODLE_JUMP_ASSETS_H
#include <SFML/Graphics.hpp>
using namespace sf;

//objects
RectangleShape background(Vector2f(500, 700));
RectangleShape player(Vector2f(80, 80));
RectangleShape platform(Vector2f(68, 14));

//textures
Texture backgroundTexture;
Texture playerRightTexture;
Texture playerLeftTexture;
Texture platformTexture;

//Font
Font fontGame;

void getAssets() {
	//routes
	backgroundTexture.loadFromFile("resources/images/background.png");
	playerRightTexture.loadFromFile("resources/images/playerRight.png");
	playerLeftTexture.loadFromFile("resources/images/playerLeft.png");
	platformTexture.loadFromFile("resources/images/platform.png");
	fontGame.loadFromFile("resources/al-seana.ttf");

	//setup textures for objects
	background.setTexture(&backgroundTexture);
	player.setTexture(&playerRightTexture);
	platform.setTexture(&platformTexture);

}
#endif
