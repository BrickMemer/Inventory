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

void dungeon::SimulateFight(player& CurrentPlayer)
{
    bool FightResult = FightingSystem::SimulateFight(CurrentPlayer, this->floors[this->curentFloor]);
    if(FightResult == false)
    {
        CurrentPlayer.Death();
    }
}

void dungeon::DisplayFight()
{
    FightDisplay::DislplayFight(this->getFloor());
}

void dungeon::PlayerAttack(int damage, int index)
{
    this->floors[this->curentFloor].DamageEnemy(index, damage);
}

Floor& dungeon::getFloor()
{
    return this->floors[this->curentFloor];
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
