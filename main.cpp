#include "game.hpp"

int main()
{
    game game1;

    #ifdef unix
        system("stty -echo");
        system("stty cbreak");
    #endif

    game1.RunGame();

    std::system("stty echo");
    std::system("stty -cbreak");

    return 0;
}

