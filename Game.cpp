#include "include/Game.hpp"

Game::Game():
    mWindow(sf::VideoMode(1600,900), "Pong"),
    mBall(),
    mPlayerOne(30.f, 375.f, sf::Keyboard::W, sf::Keyboard::S),
    mPlayerTwo(1520.f, 375.f, sf::Keyboard::Numpad8, sf::Keyboard::Numpad2)
{
}

void Game::run()
{
    // clock de pro
    sf::Clock clock;

    // removendo o lag
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // janela do jogo
    while (mWindow.isOpen())
    {
        // processa eventos na tela
        proccessEvents();

        // evitar lag
        timeSinceLastUpdate += clock.restart();

        // loop de atualização dos frames
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
                mPlayerOne.handleInput(event.key.code, true);
                mPlayerTwo.handleInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                mPlayerOne.handleInput(event.key.code, false);
                mPlayerTwo.handleInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }

}

void Game::update(sf::Time timePerFrame)
{
    bool changeDirection = mBall.getGlobalBounds().intersects(mPlayerOne.getGlobalBounds()) ||
        mBall.getGlobalBounds().intersects(mPlayerTwo.getGlobalBounds()) ;
    mPlayerOne.update(timePerFrame, mWindow.getSize().y);
    mPlayerTwo.update(timePerFrame, mWindow.getSize().y);
    mBall.update(timePerFrame, mWindow.getSize().y, changeDirection);
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mBall);
    mWindow.draw(mPlayerOne);
    mWindow.draw(mPlayerTwo);
    mWindow.display();
}
