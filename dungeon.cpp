#include "dungeon.hpp"
#include "fightingsystem.hpp"
#include "fightdisplay.hpp"

//Be default set dungeon size to 10 and level to 1
dungeon::dungeon() : Size(10), level(1)
{
    this->GenerateDungeon();
}

dungeon::dungeon(int level, int size) : Size(size), level(level) {}

//generate as much floors, as big is the dungeon
void dungeon::GenerateDungeon()
{
    for(int i = 0; i < this->Size; i++)
    {
        this->NewFloor();
    }
}

void dungeon::NewFloor()
{
    for(int i = 0; i < this->Size; i++)
    {
        this->floors.push_back(Floor(this->level));
    }
}

//The Fighting system determents how much monster did attack to the player
bool dungeon::EnemyAttack(player& CurrentPlayer)
{
    bool FightResult = FightingSystem::SimulateFight(CurrentPlayer, this->floors[this->curentFloor]);
    if(FightResult == true)
    {
        CurrentPlayer.Death();
    }
    return FightResult;
}

//Calls FightDisplay Function
void dungeon::DisplayFight(const int& CurrentChoice, const std::string& BackGroundSpritesName)
{
    FightDisplay::DislplayFight(this->getFloor(), CurrentChoice);
}

int dungeon::PlayerAttack(int damage, int index)
{
    const int MoneyGained = this->floors[this->curentFloor].DamageEnemy(index, damage);
    return MoneyGained;
}

Floor& dungeon::getFloor()
{
    return this->floors[this->curentFloor];
}

Enemy& dungeon::GetEnemy(int index) const
{
    return *this->floors[this->curentFloor].getEnemies()[index];
}

// Moves current floor by one, if's bigger then the size, return false
bool dungeon::MoveForward()
{
    if(this->curentFloor + 1 >= this->Size)
    {
        return false;
    }
    else
    {
        this->curentFloor++;
        return true;
    }
}
