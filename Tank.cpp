#include "Tank.hpp"

Tank::Tank()
: Sprite()
{
    _tank_texture.loadFromFile("resources/images/tank_to_right.png");

    setTexture(_tank_texture);
    setPosition(400.f, 300.f);
}
