#include "singleCharacter.hpp"

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

bool performAction(player& CurrentPlayer)
{
    char input = getSingleChar();
    switch(input)
    {
    case 'n':
        CurrentPlayer.AddItem(new Weapon("Sword", 5, 4, 5));
        break;
    case 'A':
        CurrentPlayer.AlignItems();
        break;
    case 'c':
        CurrentPlayer.ClearItems();
        break;
    case 'q':
        return false;
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
    case 'i':
        do
        {
            std::system(CLEAR);
            if(CurrentPlayer.GetInfo() == false)
            {
                std::cout << "No valid item is present under your selection, please try again" << '\n'
                          << "Press any key to continue ...";
            }
        }while(!getchar());
        break;
    case 'a':
        CurrentPlayer.MoveX(true);
        break;
    case 'w':
        CurrentPlayer.MoveY(true);
        break;
    case 'd':
        CurrentPlayer.MoveX(false);
        break;
    case 's':
        CurrentPlayer.MoveY(false);
        break;
    default:
        break;
    }
    std::system(CLEAR);
    return true;
}
