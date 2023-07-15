#ifndef DOODLE_JUMP_PLATFORM_H
#define DOODLE_JUMP_PLATFORM_H
#include <SFML/Graphics.hpp>
using namespace sf;

void generationPlatform(Vector2f positionPlatform[10]);

void renderingPlatform(RectangleShape platform, RenderWindow& window, Vector2f positionPlatform[10]);

void checkCollisionPlatform(Vector2f positionPlayer, Vector2f positionPlatform[10], float &dy);

void resetPlatform(Vector2f &positionPlayer, Vector2f positionPlatform[10], float &dy);

#endif