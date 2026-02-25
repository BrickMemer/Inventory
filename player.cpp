#include "player.hpp"

player::player() : PlayerInventory(5,5)
{
    this->PlayerInventory.ResetCorrdinates();
    //this->PlayerInventory.AddItem(new Weapon());
    this->Equipment = this->PlayerInventory.GetRow();
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
    for(int x = 0; x < this->PlayerInventory.GetRowsMaxSize(); x++)
    {
        if(this->Equipment[x]->getItem())
        {
            this->damage += this->Equipment[x]->getItem()->getAttribute().getDamage();
        }
    }
}

void player::RecalculateStats()
{
    this->setDefense();
    this->setDamage();
}

void player::Death()
{
    this->PlayerInventory.Clear();
    this->Money = 250;
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
    for(int x = 0; x < this->PlayerInventory.GetRowsMaxSize(); x++)
    {
        if(this->Equipment[x]->getItem())
        {
            this->defense += this->Equipment[x]->getItem()->getAttribute().getDefense();
        }
    }
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

bool player::MoveToEquipment()
{
    int EquipmentFreeSpace = -1;
    for (int i = 0; i < this->PlayerInventory.GetRowsMaxSize(); ++i)
    {
        if(!this->Equipment[i])
        {
            EquipmentFreeSpace = i;
        }
    }
    if(EquipmentFreeSpace < 0)
    {
        return false;
    }
    else
    {
        this->PlayerInventory.MoveOrSwap(this->PlayerInventory.getCurrentX(), this->PlayerInventory.getCurrentY(), 0, EquipmentFreeSpace);
        return true;
    }
    this->RecalculateStats();
}

bool player::AddItem(Item* item)
{
    if(this->PlayerInventory.AddItem(item))
    {
        this->RecalculateStats();
        return true;
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
