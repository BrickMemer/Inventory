#include "player.hpp"


player::player() : PlayerInventory(16,5)
{
    this->PlayerInventory.Set(new Item("Sdord", 5 ,4), 3 , 4);
}

void player::DisplayInventory()
{
    std::thread tD(&Inventory::DisplayInventory, &this->PlayerInventory);

    tD.join();
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

 void player::ClearItems()
{
    this->PlayerInventory.Clear();
}

void player::AlignItems()
{
    std::thread tA(&Inventory::Align, &this->PlayerInventory);

    tA.join();
}
