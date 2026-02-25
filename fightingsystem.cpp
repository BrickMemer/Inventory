#include "fightingsystem.hpp"

bool FightingSystem::SimulateFight(player& currentPlayer, Floor& CurrentFloor)
{
    currentPlayer.setHealth(currentPlayer.getHealth() + currentPlayer.getDefense() - CurrentFloor.getRandEnemy()->Attak());
    if(currentPlayer.getHealth() < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
