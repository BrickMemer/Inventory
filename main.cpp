#include <iostream>
#include "inventory.hpp"
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

void performAction() {
    std::cout << "Press any key: ";
    char ch = getSingleChar(); // Get single key press
    std::system(CLEAR);
    std::cout << "\nYou pressed: " << ch << std::endl;
}


int main()
{
    Inventory inv(5,5);

    #ifdef unix
        system("stty -echo");
        system("stty cbreak");
    #endif

    char input = ' ';
    while(true)
    {
        inv.DisplayInventory();
        input = getSingleChar();
        if(input == 'a')
        {
            inv.AddItem(new Item("Sword", 5, 4));
        }
        std::system("clear");
    }
    return 0;
}

