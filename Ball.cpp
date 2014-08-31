#include "include/Ball.hpp"

Ball::Ball() : CircleShape()
{
    // o tamanho da bolinha
    this->setRadius(40.f);

    // posicionamento inicial da bolinha
    this->setPosition(100.f, 100.f);

    //cor da bolinha
    this->setFillColor(sf::Color::Cyan);
}

void Ball::update(const sf::Time &timePerFrame, float winHeight, bool changeDirection)
{
    sf::Vector2f movement(0.f, 0.f);

    static int stepX = 300;
    static int stepY = 300;

    if ( getPosition().y < 0)
        stepY *= -1;
    if ( getPosition().y >= 870.f - 40.f - 10.f )
        stepY *= -1;
    if ( changeDirection )
        stepX *= -1;

    movement.x += stepX;
    movement.y += stepY;

    move(movement * timePerFrame.asSeconds());
}
