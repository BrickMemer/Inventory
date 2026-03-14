#include "fightdisplay.hpp"
#include "battleground.hpp"
#include "displaycells.hpp"

FightDisplay::FightDisplay() {}

void FightDisplay::DislplayFight(const Floor& CurrentFloor, const int& CurrentChoice)
{
    std::vector<std::string> BattleGroundSpritesNames;
    BattleGroundSpritesNames.push_back("BrickWall");
    for (const auto enemy : CurrentFloor.getEnemies())
    {
        BattleGroundSpritesNames.push_back(enemy->getName());
    }
    BattleGroundSpritesNames.push_back("BrickWall");
    BattleGround battleground(BattleGroundSpritesNames);
    battleground.DrawBattleGround();
    DisplayCells::DisplayFullCells(1, std::vector<std::string>{"fight", "leave", "act", "items"}, CurrentChoice, 0, 24, 24, 6);
}
