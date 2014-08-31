#include "Tank.hpp"

Tank::Tank()
: Sprite(),
  _tank_texture()
{
    _is_moving_up = true;
    _is_moving_down = false;
    _is_moving_left = false;
    _is_moving_right = false;

    setPosition(400.f, 300.f);

    _tank_texture.loadFromFile("resources/images/tank_to_up.png");
    setTexture(_tank_texture);

    setOrigin(28, 63);
}

void Tank::handleInput(sf::Keyboard::Key key, bool is_pressed)
{
  if (sf::Keyboard::Up == key)
    _is_moving_up = is_pressed;
  if (sf::Keyboard::Down == key)
    _is_moving_down = is_pressed;
  if (sf::Keyboard::Right == key)
    _is_moving_right = is_pressed;
  if (sf::Keyboard::Left == key)
    _is_moving_left = is_pressed;
}

void Tank::update()
{
  static float angle = 0.f;

  if (_is_moving_up)
    angle = 0.f;
  else if (_is_moving_down)
    angle = 180.f;
  else if (_is_moving_right)
    angle = 90.f;
  else if (_is_moving_left)
    angle = 270.f;

  setRotation(angle);
}
