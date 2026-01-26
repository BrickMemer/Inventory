#include "game.hpp"

game::game(player &CurrentPlayer) : CurrentPlayer(CurrentPlayer) {}

bool game::getIsRunning() const
{
    return IsRunning;
}

void game::Run()
{
    this->CurrentPlayer.DisplayInventory();
    this->IsRunning = performAction(this->CurrentPlayer);
}
