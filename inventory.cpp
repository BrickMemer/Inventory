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

Item* Inventory::GetItem()
{
    if(!this->Items[this->CurrentX][this->CurrentY])
    {
        return nullptr;
    }
    else
    {
        return Items[this->CurrentX][this->CurrentY]->getItem();
    }
}

bool Inventory::SetItem(Item* item)
{
    this->Items[this->CurrentX][this->CurrentY]->setItem(item);
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
        Item* TempItem1 = this->Items[x][y]->getItem();
        Item* TempItem2 = this->Items[newx][newy]->getItem();
        this->Items[x][y]->setItem(TempItem2);
        this->Items[newx][newy]->setItem(TempItem1);
        return true;
    }
}

bool Inventory::AddItem(Item* item)
{
    for(int i = 0; i < this->Rows; i++)
    {
        for(int j = 0; j < this->Columns; j++)
        {
            if(this->Items[i][j]->getItem() == nullptr)
            {
                this->Items[i][j]->setItem(item);
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
        Item* TempItem = this->Items[this->CurrentX][this->CurrentY]->getItem();
        this->Items[this->CurrentX][this->CurrentY]->setItem(nullptr);
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
        delete this->Items[this->CurrentX][this->CurrentY]->getItem();
        this->Items[this->CurrentX][this->CurrentY]->setItem(nullptr);
        return true;
    }
}

bool Inventory::GetInfo()
{
    if(!this->Items[this->CurrentX][this->CurrentY]->getItem())
    {
        return false;
    }
    else
    {
        this->Items[this->CurrentX][this->CurrentY]->getItem()->getInfo();
        return true;
    }
}

void Inventory::DisplayInventory()
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
                if(col == this->CurrentY && row == this->CurrentX){
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
            if(this->Items[row][col])
            {
                delete this->Items[row][col];
                this->Items[row][col] = nullptr;
            }
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
        delete[] this->Items[i];
    }
    delete[] this->Items;
}
