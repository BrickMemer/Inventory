#include "inventory.hpp"

Inventory::Inventory(unsigned int Rows, unsigned int Columns) : Rows(Rows),
    Columns(Columns)
{
    this->Items = new Item**[Rows];
    for(unsigned int i = 0; i < this->Rows; i++)
    {
        this->Items[i] = new Item*[Columns];
        for(unsigned int j = 0; j < this->Columns; j++)
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

bool Inventory::MoveOrSwap(int x,int y,int newx,int newy)
{
    if(x >= this->Rows || y >= this->Columns || newx >= this->Rows || newy >= this->Columns)
    {
        return false;
    }
    else if(!this->Items[x][y] && !this->Items[newx][newy])
    {
        return false;
    }
    else
    {
        Item* TempItem = Get(x, y);
        Item* TempItem2 = Get(newx, newy);
        Set(TempItem, newx, newy);
        Set(TempItem2, x, y);
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
                std::unique_lock<std::shared_mutex> lock(this->Shared_mtx);
                this->Items[i][j] = Item;
                return true;
            }
        }
    }
    delete Item;
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

void Inventory::DisplayInventory(unsigned int x, unsigned int y)
{
    unsigned short SpaceBetween = 24;
    for(size_t i = 0; i < this->Rows; i++)
    {
        for(size_t j = 0; j < this->Columns; j++)
        {
            std::string NameToDisplay;
            if(i == y && j == x)
            {
                NameToDisplay.append("{");
            }
            else
            {
                NameToDisplay.append("[");
            }
            if(this->Items[i][j])
            {
                std::unique_lock<std::shared_mutex> lock(this->Shared_mtx);
                short MiddleSpot = static_cast<short>((SpaceBetween - Items[i][j]->getName().length()) / 2);
                for(size_t z = 0; z < MiddleSpot; z++)
                {
                    NameToDisplay.append(" ");
                }
                NameToDisplay.append(Items[i][j]->getName());
                for(size_t z = 0; z < MiddleSpot; z++)
                {
                    NameToDisplay.append(" ");
                }
                if(Items[i][j]->getName().length() % 2 != 0)
                {
                    NameToDisplay.append(" ");
                }
            }
            else
            {
                for(size_t z = 0; z < SpaceBetween; z++)
                {
                    std::unique_lock<std::shared_mutex> lock(this->Shared_mtx);
                    NameToDisplay.append(" ");
                }
            }
            if(i == y && j == x)
            {
                NameToDisplay.append("}");
            }
            else
            {
                NameToDisplay.append("]");
            }
            std::cout << NameToDisplay;
        }
        std::cout << '\n';
    }
}

void Inventory::Align()
{
    std::queue<std::pair<int, int>> FreeCordinates;

    for(int i = 0; i < this->Rows; i++)
    {
        for(int j = 0; j < this->Columns; j++)
        {
            if(this->Items[i][j] && FreeCordinates.size() > 0)
            {
                std::unique_lock<std::shared_mutex> lock(this->Shared_mtx);
                this->MoveOrSwap(i,j,FreeCordinates.front().first, FreeCordinates.front().second);
                FreeCordinates.pop();
            }
            else if(!this->Items[i][j])
            {
                FreeCordinates.push(std::make_pair(i,j));
            }
        }
    }
}

void Inventory::Clear()
{
    for(int i = 0; i < this->Rows; i++)
    {
        for(int j = 0; j < this->Columns; j++)
        {
            this->Remove(i,j);
        }
    }
}

unsigned int Inventory::GetColumnsMaxSize()
{
    return this->Columns;
}

unsigned int Inventory::GetRowsMaxSize()
{
    return this->Rows;
}

Inventory::~Inventory()
{
    for(int i = 0; i < this->Rows; i++)
    {
        delete[] this->Items[i];
    }
    delete[] this->Items;
}
