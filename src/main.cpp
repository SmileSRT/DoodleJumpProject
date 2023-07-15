#include "assets.h"
#include "platform.h"
#include "menu.h"
#include "consts.h"

int main()
{
    RenderWindow window(VideoMode(500, 700), "DoodleJump");
    getAssets();

    Text scoreText;
    formattingText(*&scoreText, 40, Vector2f(20, 10), "");

    Vector2f moveRec;           //to movement player
    Vector2f posPlayer;         //to save current position player
    Vector2f posPlatform[10];   //to save positions platforms
    Clock clock;                //to bind the gameplay to time
    float dy = 0;               //to set the jump height
    int score = 1;

    //start positions
    player.setPosition(210, 200);
    generationPlatform(posPlatform);

    startMenu(window);

    while (window.isOpen()){

        //bind the gameplay to time
        float time = clock.getElapsedTime().asMicroseconds();
        float timePlayer = time / 3000;
        float timeJump = time / 700;
        clock.restart();

        //event - control gameplay from the keyboard
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed) {
                window.close();
            }
            //control player
            switch (event.type) {
            case Event::KeyPressed:
                if (event.key.code == Keyboard::A || event.key.code == Keyboard::Left) {
                    moveRec.x = -1.2 * timePlayer;
                    player.setTexture(&playerLeftTexture); //Texture change when changing player side
                }
                if (event.key.code == Keyboard::D || event.key.code == Keyboard::Right) {
                    moveRec.x = 1.2 * timePlayer;
                    player.setTexture(&playerRightTexture);
                }
                break;
            case Event::KeyReleased:
                if (event.key.code == Keyboard::A || event.key.code == Keyboard::Left) {
                    moveRec.x = 0;
                }
                if (event.key.code == Keyboard::D || event.key.code == Keyboard::Right) {
                    moveRec.x = 0;
                }
                break;
            }
        }

        player.move(moveRec);
        posPlayer = player.getPosition();

        //Jump mechanics
        dy += 0.001 * timeJump;
        posPlayer.y += dy;

        resetPlatform(posPlayer, posPlatform, dy);
        player.setPosition(posPlayer.x, posPlayer.y);

        //out of range window
        if (posPlayer.x <= -40) {
            player.setPosition(460, posPlayer.y);
        }
        if (posPlayer.x >= 460) {
            player.setPosition(-40, posPlayer.y);
        }

        checkCollisionPlatform(posPlayer, posPlatform, dy);

        //game end condition
        if (posPlayer.y > 620) {
            endMenu(window, scoreText);
            player.setPosition(posPlatform[3].x, posPlatform[3].y);
            score = 1;
        }

        //score
        if (posPlayer.y == LIFTING_HEIGHT && dy < (-0.3)) {
            score += 1;
            scoreText.setString(std::to_string(score));
        }
        
        window.clear();
        window.draw(background);
        renderingPlatform(platform, window, posPlatform);
        window.draw(player);
        window.draw(scoreText);
        window.display();
    }
    return 0;
}