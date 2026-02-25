#include "player.hpp"

player::player() : PlayerInventory(5,5)
{
    //this->PlayerInventory.AddItem(new Weapon());
}

unsigned int player::getMoney() const
{
    return Money;
}

void player::AddMoney(unsigned int MoneyToAdd)
{
    this->Money = this->Money + MoneyToAdd;
}

void player::SubstractMoney(unsigned int MoneyToSubstract)
{
    this->Money = this->Money - MoneyToSubstract;
}

int player::getHealth() const
{
    return health;
}

void player::setHealth(int newHealth)
{
    health = newHealth;
}

int player::Attack() const
{
    return damage;
}

void player::setDamage()
{
    this->damage = 0;
    int CurrentX = this->PlayerInventory.getCurrentX();
    int CurrentY = this->PlayerInventory.getCurrentY();
    for(int x = 0; x < this->PlayerInventory.GetColumnsMaxSize(); x++)
    {
        for(int y = 0; y < this->PlayerInventory.GetRowsMaxSize(); y++)
        {
            this->PlayerInventory.SetCorrdinates(x,y);
            this->damage +=this->PlayerInventory.GetItem()->getAttribute().getDamage();
        }
    }
    this->PlayerInventory.SetCorrdinates(CurrentX, CurrentY);
}

void player::RecalculateStats()
{
    this->setDefense();
    this->setDamage();
}

void player::Death()
{
    this->PlayerInventory.Clear();
    this->Money = 100;
}

void player::Revive()
{
    this->health = 100;
}

int player::getDefense() const
{
    return defense;
}

void player::setDefense()
{
    this->defense = 0;
    int CurrentX = this->PlayerInventory.getCurrentX();
    int CurrentY = this->PlayerInventory.getCurrentY();
    for(int x = 0; x < this->PlayerInventory.GetColumnsMaxSize(); x++)
    {
        for(int y = 0; y < this->PlayerInventory.GetRowsMaxSize(); y++)
        {
            this->PlayerInventory.SetCorrdinates(x,y);
            this->defense +=this->PlayerInventory.GetItem()->getAttribute().getDefense();
        }
    }
    this->PlayerInventory.SetCorrdinates(CurrentX, CurrentY);
}

void player::DisplayInventory()
{
    this->PlayerInventory.DisplayInventory();
}
bool player::MoveX(bool UpOrDown)
{
    if(UpOrDown == true)
    {
        return this->PlayerInventory.SetCorrdinates(this->PlayerInventory.getCurrentX() - 1, this->PlayerInventory.getCurrentY());
    }
    else
    {
        return this->PlayerInventory.SetCorrdinates(this->PlayerInventory.getCurrentX() + 1, this->PlayerInventory.getCurrentY());
    }
}
bool player::MoveY(bool LeftOrRight)
{
    if(LeftOrRight == true)
    {
        return this->PlayerInventory.SetCorrdinates(this->PlayerInventory.getCurrentX(), this->PlayerInventory.getCurrentY() - 1);
    }
    else
    {
        return this->PlayerInventory.SetCorrdinates(this->PlayerInventory.getCurrentX(), this->PlayerInventory.getCurrentY() + 1);
    }
}

bool player::AddItem(Item* item)
{
    if(this->PlayerInventory.AddItem(item))
    {
        this->RecalculateStats();
        return true;    return false;
    }
    else
    {
        return false;
    }
}

void player::ClearItems()
{
    this->PlayerInventory.Clear();
    this->RecalculateStats();
}

bool player::GetInfo()
{
    return this->PlayerInventory.GetInfo();
}

Item* player::GetItem()
{
    return this->PlayerInventory.GetItem();
}

void player::AlignItems()
{
    this->PlayerInventory.Align();
}

void player::RemoveItem()
{
    this->RecalculateStats();
    this->PlayerInventory.Remove();
}

void player::ResetCorrdinates()
{
    this->PlayerInventory.ResetCorrdinates();
}
