#ifndef FIGHTDISPLAY_HPP
#define FIGHTDISPLAY_HPP

#include "floor.hpp"
#include "battleground.hpp"

class FightDisplay
{
public:
    FightDisplay();

    static void DislplayFight(const Floor& CurrentFloor, const int& CurrentChoice, BattleGround& battleground);
};

#endif // FIGHTDISPLAY_HPP
