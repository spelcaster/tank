#ifndef GAME_TANK
#define GAME_TANK

#include <SFML/Graphics.hpp>
#include "Tank.hpp"

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

        // jogador 1
        Tank _player_one;
};

#endif
