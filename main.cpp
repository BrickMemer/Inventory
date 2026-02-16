#include <iostream>
#include "game.hpp"

int main()
{
    player player1;
    game game1(player1);

    #ifdef unix
        system("stty -echo");
        system("stty cbreak");
    #endif

    std::system(CLEAR);

    game1.RunGame();

    std::system("stty echo");
    std::system("stty -cbreak");

    return 0;
}

