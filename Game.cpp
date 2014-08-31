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
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }

}

void Game::update(sf::Time timePerFrame)
{
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(_player_one);
    mWindow.display();
}
