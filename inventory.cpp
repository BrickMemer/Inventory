#include "inventory.hpp"

Inventory::Inventory(unsigned int Rows, unsigned int Columns) : Rows(Rows),
    Columns(Columns)
{
    this->Items = new InventoryCell**[Rows];
    for(unsigned int i = 0; i < this->Rows; i++)
    {
        this->Items[i] = new InventoryCell*[Columns];
        for(unsigned int j = 0; j < this->Columns; j++)
        {
            this->Items[i][j] = new InventoryCell();
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
        return Items[x][y]->getItem();
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
        this->Items[x][y]->setItem(Item);
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
            if(this->Items[i][j]->getItem() == nullptr)
            {
                std::unique_lock<std::shared_mutex> lock(this->Shared_mtx);
                this->Items[i][j]->setItem(Item);
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
    else if(this->Items[x][y]->getItem())
    {
        Item* TempItem = Get(x, y);
        this->Items[x][y]->setItem(nullptr);
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
    else if(this->Items[x][y]->getItem())
    {
        delete this->Items[x][y]->getItem();
        this->Items[x][y]->setItem(nullptr);
        return true;
    }
    else
    {
        return false;
    }
}

bool Inventory::GetInfo(const unsigned int x, const unsigned int y)
{
    if(x >= this->Rows || y >= this->Columns)
    {
        return false;
    }
    else if(this->Items[x][y]->getItem())
    {
        this->Items[x][y]->getItem()->getInfo();
        return true;
    }
    else
    {
        return false;
    }
}

void Inventory::DisplayInventory(const unsigned int x, const unsigned int y)
{
    unsigned short SpaceBetween = 24;
    for(size_t row = 0; row < this->Rows; row++)
    {
        int levels = 6;
        std::string NameToDisplay;
        for (int level = 0; level < levels; ++level) {
            bool isSelected = false;
            for(size_t col = 0; col < this->Columns; col++)
            {
                if(col == x && row == y){
                    isSelected = true;
                }
                std::cout << this->Items[row][col]->display(level, isSelected);
                isSelected = false;
            }
            std::cout << "\n";
        }

    }
}

void Inventory::Align()
{
    std::queue<std::pair<int, int>> FreeCordinates;

    for(int row = 0; row < this->Rows; row++)
    {
        for(int col = 0; col < this->Columns; col++)
        {
            if(this->Items[row][col]->getItem() && FreeCordinates.size() > 0)
            {
                std::unique_lock<std::shared_mutex> lock(this->Shared_mtx);
                this->MoveOrSwap(row,col,FreeCordinates.front().first, FreeCordinates.front().second);
                FreeCordinates.pop();
            }
            else if(!this->Items[row][col]->getItem())
            {
                FreeCordinates.push(std::make_pair(row,col));
            }
        }
    }
}

void Inventory::Clear()
{
    for(int row = 0; row < this->Rows; row++)
    {
        for(int col = 0; col < this->Columns; col++)
        {
            this->Remove(row,col);
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
