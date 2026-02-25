#ifndef FIGHTINGSYSTEM_HPP
#define FIGHTINGSYSTEM_HPP

#include "dungeon.hpp"

class FightingSystem
{
public:
    static bool SimulateFight(player& currentPlayer, Floor& CurrentFloor);
};

#endif // FIGHTINGSYSTEM_HPP
