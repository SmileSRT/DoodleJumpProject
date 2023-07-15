#include "platform.h"
#include "consts.h"

void generationPlatform(Vector2f positionPlatform[10]) {
	for (int i = 0; i < 10; i++) {
		positionPlatform[i].x = rand() % 500;
		positionPlatform[i].y = rand() % 700;
	}
	
}

void renderingPlatform(RectangleShape platform, RenderWindow& window, Vector2f positionPlatform[10]) {
	for (int i = 0; i < 10; i++) {
		platform.setPosition(positionPlatform[i].x, positionPlatform[i].y);
		window.draw(platform);
	}
}

void checkCollisionPlatform(Vector2f positionPlayer, Vector2f positionPlatform[10], float &dy) {
	for (int i = 0; i < 10; i++) {
		if ((positionPlayer.x + DOODLER_RIGHT_SIZE > positionPlatform[i].x) 
			&& (positionPlayer.x + DOODLER_LEFT_SIZE < positionPlatform[i].x + PLATFORM_RIGHT_SIZE) 
			&& (positionPlayer.y + DOODLER_DOWN_SIZE > positionPlatform[i].y) 
			&& (positionPlayer.y + DOODLER_DOWN_SIZE < positionPlatform[i].y + PLATFORM_DOWN_SIZE)
			&& dy > 0) {
			dy = -0.8;
		}
	}
	
}

void resetPlatform(Vector2f &positionPlayer, Vector2f positionPlatform[10], float &dy) {
	if (positionPlayer.y < LIFTING_HEIGHT) {
		for (int i = 0; i < 10; i++) {
			positionPlayer.y = LIFTING_HEIGHT;
			positionPlatform[i].y -= dy;
			if (positionPlatform[i].y > 700) {
				positionPlatform[i].y = 0;
				positionPlatform[i].x = rand() % 500;
			}
		}
	}

}
