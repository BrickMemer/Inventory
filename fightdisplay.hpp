#ifndef FIGHTDISPLAY_HPP
#define FIGHTDISPLAY_HPP

#include "floor.hpp"

class FightDisplay
{
public:
    FightDisplay();

    static void DislplayFight(const Floor& CurrentFloor);
};

#endif // FIGHTDISPLAY_HPP
