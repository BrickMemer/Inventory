#include "dungeon.hpp"
#include "fightingsystem.hpp"
#include "fightdisplay.hpp"

dungeon::dungeon() : Size(10), level(1)
{
    this->GenerateDungeon();
}

dungeon::dungeon(int level, int size) : Size(size), level(level) {}

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

bool dungeon::EnemyAttack(player& CurrentPlayer)
{
    bool FightResult = FightingSystem::SimulateFight(CurrentPlayer, this->floors[this->curentFloor]);
    if(FightResult == true)
    {
        CurrentPlayer.Death();
    }
    return FightResult;
}

void dungeon::DisplayFight(const int& CurrentChoice)
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

bool dungeon::MoveForward()
{
    if(++this->curentFloor >= this->Size)
    {
        return false;
    }
    else
    {
        return true;
    }
}
