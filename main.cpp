#include <iostream>
#include "player.hpp"
#include "weapon.h"
/*
#include <cstdlib>
#include <unistd.h>
*/
#ifdef _WIN32
#include <conio.h> // For _getch() on Windows
#define OS_NAME "Windows"
#define CLEAR "cls"
#elif __APPLE__
#include <TargetConditionals.h>
#include <termios.h>
#include <unistd.h>
#elif TARGET_OS_MAC
#define OS_NAME "macOS"
#define CLEAR "clear"
#elif unix
#define OS_NAME "unix"
#define CLEAR "clear"
#else
#define OS_NAME "Unknown OS"
#define CLEAR "clear"
#endif

char getSingleChar() {
#ifdef _WIN32
    return _getch(); // Windows: Get character without Enter
#elif __APPLE__
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt); // Get current terminal attributes
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable line buffering & echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new attributes
    ch = getchar(); // Read single character
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old attributes
    return ch;
#elif unix
    return getchar();
#endif
}
static bool run = true;

void performAction(player& CurrentPlayer)
{
    char input = getSingleChar();
    switch(input)
    {
        case 'a':
            CurrentPlayer.AddItem(new Weapon("Sword", 5, 4, 5));
            break;
        case 'A':
            CurrentPlayer.AlignItems();
            break;
        case 'c':
            CurrentPlayer.ClearItems();
            break;
        case 'q':
            run = false;
            break;
        case 'h':
            do
            {
                std::system(CLEAR);
                std::cout << "Press 'a' to add a new item" << '\n'
                          << "Press 'A' to align all the items in order" << '\n'
                          << "Press 'q' to quit" << '\n'
                          << "Press 'c' to clear inventory" << '\n'
                          << '\n'
                          << "Press any key to continue ...";
            }while(!getchar());
            break;
        case 'v':
            CurrentPlayer.MoveX(true);
            break;
        case 'b':
            CurrentPlayer.MoveY(true);
            break;
        case 'm':
            CurrentPlayer.MoveX(false);
            break;
        case 'n':
            CurrentPlayer.MoveY(false);
            break;
    }
}


int main()
{
    player player1;

    #ifdef unix
        system("stty -echo");
        system("stty cbreak");
    #endif

    std::system(CLEAR);

    //Disabled due to bugs
    std::cout << "Welcome to Inventory Symulator, if you need help, press 'h'" << '\n';

    while(run == true)
    {
        player1.DisplayInventory();

        performAction(player1);

        std::system(CLEAR);
    }

    std::system("stty echo");
    std::system("stty -cbreak");

    return 0;
}

