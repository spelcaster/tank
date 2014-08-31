#ifndef GAME_PONG
#define GAME_PONG

#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "Rectangle.hpp"

const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f); //0,016666667

class Game
{
    public:
        Game();
        void run();

    private:
        void proccessEvents();
        void update(sf::Time timePerFrame);
        void render();

    private:
        // janela do jogo
        sf::RenderWindow mWindow;

        // bolinha
        Ball mBall;

        // raquete do jogador 1
        Rectangle mPlayerOne;

        // raquete do jogador 2
        Rectangle mPlayerTwo;
};

#endif
