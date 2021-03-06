#include "Game.hpp"
#include "Tank.hpp"

Game::Game():
    mWindow(sf::VideoMode(800,600), "Super Tank"),
    _player_one()
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
            // Tratamento de input
            case sf::Event::KeyPressed:
                _player_one.handleInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                _player_one.handleInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;

            default:
                break;
        }
    }

}

void Game::update(sf::Time timePerFrame)
{
  _player_one.update();
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(_player_one);
    mWindow.display();
}
