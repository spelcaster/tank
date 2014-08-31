#ifndef GAME_PONG_BAR
#define GAME_PONG_BAR

#include <SFML/Graphics.hpp>

using sf::RectangleShape;
using sf::Keyboard;

class Rectangle : public RectangleShape
{
    private:
        bool movingUp;
        bool movingDown;
        Keyboard::Key keyUp;
        Keyboard::Key keyDown;

    public:
        Rectangle(float x, float y, Keyboard::Key keyUp, Keyboard::Key keyDown);

        bool isMovingUp() const;
        bool isMovingDown() const;

        void setMovingUp(bool isMoving);
        void setMovingDown(bool isMoving);

        void handleInput(const sf::Keyboard::Key &key, bool isPressed);
        void update(const sf::Time &timePerFrame, float winHeight);
};

#endif
