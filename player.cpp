#include "player.hpp"

player::player() : PlayerInventory(5,5)
{
    //this->PlayerInventory.Set(new Weapon(), 3 , 4);
}

void player::DisplayInventory()
{
    std::thread tD(&Inventory::DisplayInventory, &this->PlayerInventory, this->CurrentX, this->CurrentY);

    tD.join();
    //std::cout << "x: " << this->CurrentX << "y: " << this->CurrentY << '\r';
}
bool player::MoveY(bool RightOrLeft)
{
    if(RightOrLeft == true && this->CurrentY > 0)
    {
        this->CurrentY--;
        return true;
    }
    else if(RightOrLeft == false && this->CurrentY + 1 < this->PlayerInventory.GetRowsMaxSize())
    {
        this->CurrentY++;
        return true;
    }
    else
    {
        return false;
    }
}
bool player::MoveX(bool UpOrDown)
{
    if(UpOrDown == true && this->CurrentX > 0)
    {
        this->CurrentX--;
        return true;
    }
    else if(UpOrDown == false && this->CurrentX + 1 < this->PlayerInventory.GetColumnsMaxSize())
    {
        this->CurrentX++;
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

bool player::GetInfo()
{
    return this->PlayerInventory.GetInfo(this->CurrentX, this->CurrentY);
}

void player::AlignItems()
{
    std::thread tA(&Inventory::Align, &this->PlayerInventory);

    tA.join();
}
