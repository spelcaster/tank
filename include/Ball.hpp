#ifndef GAME_PONG_BALL
#define GAME_PONG_BALL

#include <SFML/Graphics.hpp>

using sf::CircleShape;

class Ball : public CircleShape
{
    private:
        bool movingUp;
        bool movingDown;
        bool movingLeft;
        bool movingRight;

    public:
        // construtor
        Ball();

        void update(const sf::Time &timePerFrame, float winHeight, bool changeDirection);

        bool isMovingUp() const;
        bool isMovingDown() const;
        bool isMovingRight() const;
        bool isMovingLeft() const;

        void setMovingUp(bool isMoving);
        void setMovingDown(bool isMoving);
        void setMovingRight(bool isMoving);
        void setMovingLeft(bool isMoving);
}; // < vírgula

#endif
