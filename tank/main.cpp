#include "libs/config.hpp"
#include "libs/Game.hpp"

int main()
{
    cout << "Version: " << TANK_VERSION << endl;

    Game game;
    game.run();
}
