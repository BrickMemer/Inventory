#include "fightdisplay.hpp"
#include "battleground.hpp"

FightDisplay::FightDisplay() {}

void FightDisplay::DislplayFight(const Floor& CurrentFloor)
{
    BattleGround battleground;
    battleground.AddSprite("Walls");
    for (const auto enemy : CurrentFloor.getEnemies())
    {
        battleground.AddSprite(enemy->getName());
    }
    battleground.AddSprite("Walls");
    battleground.DrawBattleGround();
}
