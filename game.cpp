#include "game.hpp"

game::game(player &CurrentPlayer) : CurrentPlayer(CurrentPlayer)
{
    this->CurrentPlayer.AddItem(new Weapon);
}

bool game::getIsRunning() const
{
    return IsRunning;
}

void game::DisplayMainMenu(const unsigned char& SelectedOption)
{
    ClearTerminal();
    for(int i = 0; i < 2; i++)
    {
        if(i == SelectedOption)
        {
            std::cout << "->";
        }
        switch(i)
        {
            case 0:
                std::cout << "Inventory" << '\n';
                break;
            case 1:
                std::cout << "Store" << '\n';
                break;
        }
    }
}

void game::RunGame()
{
    while(this->IsRunning == true)
    {
        switch(this->RunMainMenu())
        {
        case 0:
            RunInventory();
            break;
        case 1:
            RunStore();
            break;
        default:
            StopGame();
            break;
        }
    }
}

int game::RunMainMenu()
{
    ClearTerminal();
    static unsigned char CurrentOption = 0;

    while(this->IsRunning)
    {
        this->DisplayMainMenu(CurrentOption);
        switch(performActionMainMenu(CurrentOption))
        {
        case 0:
            StopGame();
            break;
        case 2:
            return CurrentOption;
        }
        if(CurrentOption >= 2)
        {
           CurrentOption--;
        }
    }
    StopGame();
    return 99;
}

void game::RunInventory()
{
    ClearTerminal();
    std::cout << "Welcome to Inventory Symulator, if you need help, press 'h'" << '\n';

    while(this->IsRunning)
    {
        this->CurrentPlayer.DisplayInventory();
        switch(performActionGame(this->CurrentPlayer))
        {
        case 0:
            return;
            break;
        case 2:
            this->CurrentPlayer.ResetCorrdinates();
            ClearTerminal();
            this->RunStore();
            break;
        }
    }
}

void game::RunStore()
{
    ClearTerminal();
    std::cout << "Welcome to the Store, if you need help, press 'h'" << '\n';

    bool IsStoreRunning = true;
    while (IsStoreRunning)
    {
        this->store.DisplayStore();
        switch (performActionStore(this->CurrentPlayer, this->store))
        {
        case 0:
            this->CurrentPlayer.ResetCorrdinates();
            ClearTerminal();
            return;
        }
    }
}

void game::StopGame()
{
    this->IsRunning = false;
}
