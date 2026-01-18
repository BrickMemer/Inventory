#include "player.hpp"


player::player(std::shared_mutex& mtx) : PlayerInventory(5,5, mtx) {}

void player::DisplayInventory()
{
    this->PlayerInventory.DisplayInventory();
}
bool player::MoveX(bool RightOrLeft)
{
    if(RightOrLeft == true && this->CurrentX - 1 > 0)
    {
        this->CurrentX--;
        return true;
    }
    else if(this->CurrentX + 1 < this->PlayerInventory.GetRowsMaxSize())
    {
        this->CurrentX++;
        return true;
    }
    else
    {
        return false;
    }
}
bool player::MoveY(bool UpOrDown)
{
    if(UpOrDown == true && this->CurrentY - 1 > 0)
    {
        this->CurrentY--;
        return true;
    }
    else if(this->CurrentY + 1 < this->PlayerInventory.GetColumnsMaxSize())
    {
        this->CurrentY++;
        return true;
    }
    else
    {
        return false;
    }
}

bool player::AddItem(Item* Item)
{
    return this->PlayerInventory.AddItem(Item);
}

void player::AlignItems()
{
    this->PlayerInventory.Align();
}
