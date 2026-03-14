#include "fightdisplay.hpp"
#include "battleground.hpp"
#include "displaycells.hpp"

FightDisplay::FightDisplay() {}

//Displayes current fight
void FightDisplay::DislplayFight(const Floor& CurrentFloor, const int& CurrentChoice)
{
    /*
     *      Configuration
     */
    std::vector<std::string> BattleGroundSpritesNames;
    BattleGroundSpritesNames.push_back("BrickWall");
    for (const auto enemy : CurrentFloor.getEnemies())
    {
        BattleGroundSpritesNames.push_back(enemy->getName());
    }
    BattleGroundSpritesNames.push_back("BrickWall");
    
    //Creats a battle ground
    BattleGround battleground(BattleGroundSpritesNames);
    //Draw is to the screen
    battleground.DrawBattleGround();
    //Display all the actions avalible
    DisplayCells::DisplayFullCells(1, std::vector<std::string>{"fight", "leave", "act", "items"}, CurrentChoice, 0, 24, 24, 6);
}
