#include "conf/config.h"
#include "game/Game.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "Version " << MajorTank_VERSION << endl;

    Game game;
    game.run();
}
