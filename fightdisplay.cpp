#include "fightdisplay.hpp"
#include "battleground.hpp"

FightDisplay::FightDisplay() {}

void FightDisplay::DislplayFight(const Floor& CurrentFloor, const int& CurrentChoice)
{
    BattleGround battleground;
    battleground.AddSprite("Walls");
    for (const auto enemy : CurrentFloor.getEnemies())
    {
        battleground.AddSprite(enemy->getName());
    }
    battleground.AddSprite("Walls");
    const int TotalLenght =  battleground.DrawBattleGround();
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < TotalLenght; ++j)
        {
            if(j == 0 || j == TotalLenght - 1)
            {
                std::cout << '|';
                continue;
            }
            else
            {
                switch(i)
                {
                case 0:
                case 1:
                case 3:
                case 4:
                    std::cout << ' ';
                    break;
                case 2:
                    if(j == TotalLenght / 3)
                    {
                        if(CurrentChoice == 0)
                        {
                            std::cout << "->";
                            j += 2;
                        }
                        std::cout << "fight";
                        j += 4;
                    }
                    else if(j == TotalLenght - TotalLenght / 3)
                    {
                        if(CurrentChoice == 1)
                        {
                            std::cout << "->";
                            j += 2;
                        }
                        std::cout << "leave";
                        j += 4;
                    }
                    else
                    {
                        std::cout << ' ';
                    }
                    break;
                case 5:
                    std::cout << '-';
                    break;
                }
            }
        }
    std::cout << '\n';
    }
}
