#include "game.hpp"

game::game(player &CurrentPlayer) : CurrentPlayer(CurrentPlayer)
{
    this->CurrentPlayer.AddItem(new Weapon);
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
        case 2:
            this->CurrentPlayer.ResetCorrdinates();
            ClearTerminal();
            this->RunStore();
        }
    }
}

void game::RunStore()
{
    bool IsStoreRunning = true;
    while (IsStoreRunning)
    {
        this->store.Display();
        switch (performActionStore(this->CurrentPlayer, this->store))
        {
        case 0:
            return;
        }
    }
}

void game::SellItem()
{
}
