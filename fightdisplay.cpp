#include "fightdisplay.hpp"
#include "battleground.hpp"
#include "displaycells.hpp"

FightDisplay::FightDisplay() {}

void FightDisplay::DislplayFight(const Floor& CurrentFloor, const int& CurrentChoice, BattleGround& battleground)
{
    BattleGround battleground;
    battleground.AddSprite("BrickWall");
    for (const auto enemy : CurrentFloor.getEnemies())
    {
        battleground.AddSprite(enemy->getName());
    }
    battleground.AddSprite("BrickWall");
    const int TotalLenght =  battleground.DrawBattleGround();
    DisplayCells::DisplayFullCells(1, std::vector<std::string>{"fight", "leave", "act", "items"}, CurrentChoice, 0);
}
