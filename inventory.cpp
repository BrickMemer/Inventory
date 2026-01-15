#include "inventory.hpp"

Inventory::Inventory(unsigned int Rows, unsigned int Columns) : Rows(Rows),
    Columns(Columns)
{
    this->Items = new Item**[Rows];
    for(unsigned int i = 0; i < this->Rows; i++)
    {
        this->Items[i] = new Item*[Columns];
        for(unsigned int j = 0; i < this->Columns; j++)
        {
            this->Items[i][j] = nullptr;
        }
    }
}

Item* Inventory::Get(const unsigned int x,const unsigned int y)
{
    if(x >= this->Rows || y >= this->Columns)
    {
        return nullptr;
    }
    if(this->Items[x][y])
    {
        return Items[x][y];
    }
    else
    {
        return nullptr;
    }
}

bool Inventory::Set(Item* Item, const unsigned int x,const unsigned int y)
{
    if(x >= this->Rows || y >= this->Columns)
    {
        return false;
    }
    else
    {
        this->Items[x][y] = Item;
        return true;
    }
}

bool Inventory::AddItem(Item* Item)
{
    for(int i = 0; i < this->Rows; i++)
    {
        for(int j = 0; j < this->Columns; j++)
        {
            if(!this->Items[i][j])
            {
                this->Items[i][j] = Item;
                return true;
            }
        }
    }
    return false;
}

Item* Inventory::Drop(const unsigned int x,const unsigned int y)
{
    if(x >= this->Rows || y >= this->Columns)
    {
        return nullptr;
    }
    else if(this->Items[x][y])
    {
        Item* TempItem = Get(x, y);
        this->Items[x][y] = nullptr;
        return TempItem;
    }
    else
    {
        return nullptr;
    }
}

bool Inventory::Remove(const unsigned int x,const unsigned int y)
{
    if(x >= this->Rows || y >= this->Columns)
    {
        return false;
    }
    else if(this->Items[x][y])
    {
        delete this->Items[x][y];
        this->Items[x][y] = nullptr;
        return true;
    }
    else
    {
        return false;
    }
}
