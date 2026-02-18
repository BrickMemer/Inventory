#include "game.hpp"

game::game(player &CurrentPlayer) : CurrentPlayer(CurrentPlayer)
{
    this->CurrentPlayer.AddItem(new Weapon);
    std::cout << "Welcome to Inventory Symulator, if you need help, press 'h'" << '\n';
}

bool game::getIsRunning() const
{
    return IsRunning;
}


void game::RunGame()
{
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
