#ifndef GAME_PONG
#define GAME_PONG

#include <SFML/Graphics.hpp>

const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

class Game
{
    public:
        bool mIsMovingUp;
        bool mIsMovingDown;
        bool mIsMovingLeft;
        bool mIsMovingRight;

    public:
        Game();
        void run();

    private:
        void proccessEvents();
        void update(sf::Time timePerFrame);
        void render();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    private:
        sf::RenderWindow mWindow;
        sf::CircleShape mPlayer;
};

#endif
