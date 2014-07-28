#include "include/config.h"
#include "Game.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "Version " << VERSION << endl;

    Game game;
    game.run();
}
