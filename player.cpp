#include "player.hpp"

player::player() : PlayerInventory(5,5)
{
    this->PlayerInventory.ResetCorrdinates();
    this->PlayerInventory.AddItem(new Weapon());
    this->Equipment = this->PlayerInventory.GetRow();
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
}

bool player::AddItem(Item* item)
{
    return this->PlayerInventory.AddItem(item);
}

void player::ClearItems()
{
    this->PlayerInventory.Clear();
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
    this->PlayerInventory.Remove();
}

void player::ResetCorrdinates()
{
    this->PlayerInventory.ResetCorrdinates();
}
