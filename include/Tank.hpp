#ifndef GAME_TANK_TANK
#define GAME_TANK_TANK

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using sf::Sprite;

class Tank : public Sprite
{
    public:
        // contrutor
        Tank();

        // tratamento de input
        void handleInput();

        // atualizando o elemento na tela
        void update();

    private:
        sf::Texture _tank_texture;

        bool _is_moving_up;
        bool _is_moving_down;
        bool _is_moving_right;
        bool _is_moving_left;


};


#endif
