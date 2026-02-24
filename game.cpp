#include "game.hpp"

game::game(player &CurrentPlayer) : CurrentPlayer(CurrentPlayer)
{
    //this->CurrentPlayer.AddItem(new Weapon);
    ClearTerminal();
}

bool game::getIsRunning() const
{
    return IsRunning;
}

void game::DisplayMainMenu(const unsigned char& SelectedOption)
{
    ClearTerminal();
    for(int i = 0; i < 3; i++)
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
            case 2:
                std::cout << "Dungeons" << '\n';
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
        case 2:
            RunDungeon();
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
            break;
        }
        if(CurrentOption >= 3)
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

void game::RunDungeon()
{
    dungeon GameDungeon;
    while(this->IsRunning)
    {
        ClearTerminal();
        if(GameDungeon.MoveForward() == false)
        {
            CurrentPlayer.Revive();
            return;
        }
        GameDungeon.DisplayFight();
        if(CurrentPlayer.getHealth() <= 0 )
        {
            CurrentPlayer.Revive();
            return;
        }
        getSingleChar();
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
