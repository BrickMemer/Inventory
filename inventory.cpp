#include "inventory.hpp"
#include "displaycells.hpp"

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

Item* Inventory::GetItem()
{
    if(!this->Items[this->CurrentX][this->CurrentY])
    {
        return nullptr;
    }
    else
    {
        return Items[this->CurrentX][this->CurrentY];
    }
}

bool Inventory::SetItem(Item* item)
{
    this->Items[this->CurrentX][this->CurrentY] = item;
    return true;
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
        Item* TempItem1 = this->Items[x][y];
        Item* TempItem2 = this->Items[newx][newy];
        this->Items[x][y] = TempItem2;
        this->Items[newx][newy] =TempItem1;
        return true;
    }
}

bool Inventory::AddItem(Item* item)
{
    for(int i = 0; i < this->Rows; i++)
    {
        for(int j = 0; j < this->Columns; j++)
        {
            if(this->Items[i][j] == nullptr)
            {
                this->Items[i][j] = item;
                return true;
            }
        }
    }

    delete item;
    return false;
}

Item* Inventory::Drop()
{
    if(!this->Items[this->CurrentX][this->CurrentY])
    {
        return nullptr;
    }
    else
    {
        Item* TempItem = this->Items[this->CurrentX][this->CurrentY];
        this->Items[this->CurrentX][this->CurrentY] = nullptr;
        return TempItem;
    }
}

bool Inventory::Remove()
{
    if(!this->Items[this->CurrentX][this->CurrentY])
    {
        return false;
    }
    else
    {
        delete this->Items[this->CurrentX][this->CurrentY];
        this->Items[this->CurrentX][this->CurrentY] = nullptr;
        return true;
    }
}

bool Inventory::GetInfo()
{
    if(!this->Items[this->CurrentX][this->CurrentY])
    {
        return false;
    }
    else
    {
        this->Items[this->CurrentX][this->CurrentY]->getInfo();
        return true;
    }
}

void Inventory::DisplayInventory()
{
    std::vector<std::string> ItemsNames;
    ItemsNames.resize(this->Columns*this->Rows);
    for (int x = 0; x < this->Rows; x++)
    {
        for(int y = 0; y < this->Columns; y++)
        {
            if(this->Items[x][y])
            {
                ItemsNames[x*this->Rows+y] = this->Items[x][y]->getName();
            }
        }
    }

    DisplayCells::DisplayFullCells(this->Rows, ItemsNames, this->getCurrentY(), this->getCurrentX(), 0, 24, 6);
}

bool Inventory::UpgradeItem()
{
    return this->Items[this->getCurrentX()][this->getCurrentY()]->upgrade();
}

Item** Inventory::GetRow()
{
    return this->Items[CurrentX];
}

void Inventory::Align()
{
    std::queue<std::pair<int, int>> FreeCordinates;

    for(int row = 0; row < this->Rows; row++)
    {
        for(int col = 0; col < this->Columns; col++)
        {
            if(this->Items[row][col] && FreeCordinates.size() > 0)
            {
                this->MoveOrSwap(row,col,FreeCordinates.front().first, FreeCordinates.front().second);
                FreeCordinates.pop();
            }
            else if(!this->Items[row][col])
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
            delete this->Items[row][col];
            this->Items[row][col] = nullptr;
        }
    }
}

void Inventory::ResetCorrdinates()
{
    this->CurrentX = 0;
    this->CurrentY = 0;
}

bool Inventory::SetCorrdinates(const unsigned int newX, const unsigned int newY)
{
    if(newX >= this->Rows|| newY >= this->Columns)
    {
        return false;
    }
    else
    {
        this->CurrentX = newX;
        this->CurrentY = newY;
        return true;
    }
}

unsigned int Inventory::GetColumnsMaxSize() const
{
    return this->Columns;
}

unsigned int Inventory::GetRowsMaxSize() const
{
    return this->Rows;
}

unsigned int Inventory::getCurrentX() const
{
    return CurrentX;
}

unsigned int Inventory::getCurrentY() const
{
    return CurrentY;
}

Inventory::~Inventory()
{
    for(int i = 0; i < this->Rows; i++)
    {
        for(int j = 0; j < this->Columns; j++)
        {
            if(this->Items[i][j])
            {
                delete this->Items[i][j];
            }
        }
        delete[] this->Items[i];
    }
    delete[] this->Items;
}
