#include "player.hpp"

unsigned int player::getMoney() const
{
    return Money;
}

void player::AddMoney(unsigned int MoneyToAdd)
{
    this->Money = this->Money + MoneyToAdd;
}

void player::SubstractMoney(unsigned int AmountOfMoneyToSubstract)
{
    this->Money = this->Money - AmountOfMoneyToSubstract;
}

player::player() : PlayerInventory(5,5)
{
    this->PlayerInventory.AddItem(new Weapon());
}

void player::DisplayInventory()
{
    std::thread tD(&Inventory::DisplayInventory, &this->PlayerInventory);

    tD.join();
    //std::cout << "x: " << this->CurrentX << "y: " << this->CurrentY << '\r';
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

bool player::AddItem(Item* Item)
{
    return this->PlayerInventory.AddItem(Item);
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
    return this->PlayerInventory.Get();
}

void player::AlignItems()
{
    std::thread tA(&Inventory::Align, &this->PlayerInventory);

    tA.join();
}

void player::RemoveItem()
{
    this->PlayerInventory.Remove();
}

void player::ResetCorrdinates()
{
    this->PlayerInventory.ResetCorrdinates();
}
