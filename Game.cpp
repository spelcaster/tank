#include "Game.hpp"

Game::Game():
    mWindow(sf::VideoMode(800,600), "Pong"),
    mPlayer()
{
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
    sf::Clock clock;

    // removendo o lag
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        proccessEvents();
        timeSinceLastUpdate += clock.restart();

        while (timeSinceLastUpdate > TIME_PER_FRAME) {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            update(TIME_PER_FRAME);
            render();
        }
    }
}


void Game::proccessEvents()
{
    sf::Event event;

    while (mWindow.pollEvent(event)) {

        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }

}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{

    if (key == sf::Keyboard::W) {
        mIsMovingUp = isPressed;
    } else if (key == sf::Keyboard::S) {
        mIsMovingDown = isPressed;
    } else if (key == sf::Keyboard::A) {
        mIsMovingLeft = isPressed;
    } else if (key == sf::Keyboard::D) {
        mIsMovingRight = isPressed;
    }

}

void Game::update(sf::Time timePerFrame)
{
    sf::Vector2f movement(0.f, 0.f);

    if (mIsMovingUp) {
        movement.y -= 100.f;
    }
    if (mIsMovingDown) {
        movement.y += 100.f;
    }
    if (mIsMovingLeft) {
        movement.x -= 100.f;
    }
    if (mIsMovingRight) {
        movement.x += 100.f;
    }

    mPlayer.move(movement * timePerFrame.asSeconds());
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}
