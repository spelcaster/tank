#include "include/config.h"
#include "include/Game.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "Version " << VERSION << endl;

    Game game;
    game.run();
}
