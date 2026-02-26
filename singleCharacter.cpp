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


int performActionDungeon(unsigned char& SelectedOption, player& CurrentPlayer)
{
    const char input = getSingleChar();

    switch(input)
    {
    case 'a':
        if(SelectedOption > 0)
        {
            SelectedOption--;
        }
        break;
    case 'd':
        SelectedOption++;
        break;
    case 'z':
        return 2;
        break;
    case 'q':
        return 0;
    }
    ClearTerminal();
    return 1;
}

int performActionMainMenu(unsigned char& SelectedOption)
{
    const char input = getSingleChar();

    switch(input)
    {
    case 'w':
        if(SelectedOption > 0)
        {
            SelectedOption--;
        }
        break;
    case 's':
        SelectedOption++;
        break;
    case 'q':
        return 0;
        break;
    case 'z':
        return 2;
        break;
    }
    std::system(CLEAR);
    return 1;
}

int performActionGame(player& CurrentPlayer)
{
    char input = getSingleChar();
    switch(input)
    {
    case 'A':
        CurrentPlayer.AlignItems();
        break;
    /*
    case 'c':
        CurrentPlayer.ClearItems();
        break;
    */
    case 'q':
        return 0;
        break;
    case 'h':
        do
        {
            std::system(CLEAR);
            std::cout << "Press w,a,s,d to move" << '\n'
                      << "Press 'A' to align all the items in order" << '\n'
                      << "Press 'q' to quit" << '\n'
                      /*
                      << "Press 'c' to clear inventory" << '\n'
                        */
                      << "Press 'S' to sell item" << '\n'
                      << "Press 'u to upgrade an item" << '\n'
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
        CurrentPlayer.MoveY(true);
        break;
    case 'w':
        CurrentPlayer.MoveX(true);
        break;
    case 'u':
    {
        bool HasChoosen = false;
        do
        {
            std::system(CLEAR);
            std::cout << "Are you sure you want to upgrade this item, it will cost you 150 money" << '\n'
                      << "Press y, or n to continue";
            switch(getchar())
            {
            case('y'):
                HasChoosen = true;
                break;
            case('n'):
                HasChoosen = true;
                ClearTerminal();
                return 1;
                break;
            }
        }while(!HasChoosen);
        do
        {
            std::system(CLEAR);
            if(CurrentPlayer.UpgradeItem() == false)
            {
                std::cout << "You don't have enough money, or the item is already upgraded to it's max level" << '\n'
                          << "Press any key to continue ...";
            }
            else
            {
                std::cout << "You have upgraded your selected item" << '\n'
                          << "Press any key to continue ...";
            }
        }while(!getchar());
    }
    case 'd':
        CurrentPlayer.MoveY(false);
        break;
    case 's':
        CurrentPlayer.MoveX(false);
        break;
    case 'z':
        ClearTerminal();
        do
        {
            if(CurrentPlayer.MoveToEquipment())
            {
                std::cout << "you have moved item into equipment";
            }
            else
            {
                std::cout << "you don't have enough space in equipment to move this item";
            }
        }while (!getSingleChar());
        break;
    case 'm':
        do
        {
            std::system(CLEAR);
            std::cout << "You currently have: " << CurrentPlayer.getMoney() << " money" << '\n';
        }while(!getchar());
        break;
    case 'S':
        do
        {
            std::system(CLEAR);
            if(!CurrentPlayer.GetItem())
            {
                std::cout << "There is no item to sell";
            }
            else
            {
                Store::SellItem(CurrentPlayer);
                break;
            }
        }while(!getchar());
        break;
    
    default:
        break;
    }
    std::system(CLEAR);
    return 1;
}

int performActionStore(player& CurrentPlayer, Store& GameStore)
{
    char input = getSingleChar();
    switch(input)
    {
    case 'a':
        GameStore.MoveY(true);
        break;
    case 'd':
        GameStore.MoveY(false);
        break;
    case 'h':
        do
        {
            std::system(CLEAR);
            std::cout << "Press a-d to move" << '\n'
                      << "Press 'b' to buy an new item, price determent by the store may differ from the value it actually is << '\n';" << '\n'
                      << '\n'
                      << "Press any key to continue ...";
        }while(!getchar());
        break;
    case 'i':
    {
        do
        {
            std::system(CLEAR);
            GameStore.GetInfo();
        }while(!getchar());
        break;
    }
    case 'b':
        std::system(CLEAR);
        std::cout << "Press y if you want to buy this item, if not press n" << '\n';
        input = getSingleChar();
        if(input == 'y')
        {
            do
            {
                std::system(CLEAR);
                if(GameStore.BuyItem(CurrentPlayer) == true)
                {
                    std::cout << "You had bought a new item (:" << '\n';
                }
                else
                {
                    std::cout << "You don't have enough space or money to buy new item ): " << '\n';
                }
                std:: cout << "You currently have: " << CurrentPlayer.getMoney() << '\n';
            }while(!getchar());
        }
        break;
    case 'm':
        do
        {
            std::system(CLEAR);
            std::cout << "You currently have: " << CurrentPlayer.getMoney() << " money" << '\n';
        }while(!getchar());
        break;
    case 'q':
        std::system(CLEAR);
        return 0;
        break;
    }
    std::system(CLEAR);
    return 1;
}

void ClearTerminal()
{
    std::system(CLEAR);
}
