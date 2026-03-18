#include "inventory.hpp"
#include <nlohmann/json.hpp>
#include <queue>
#include <fstream>
#include "displaycells.hpp"
#include "weapon.hpp"

Inventory::Inventory(unsigned int Rows, unsigned int Columns)
{
    this->Items.resize(Rows);

    for(auto& ItemRow: this->Items)
    {
        ItemRow.resize(Columns);
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
    if(x >= this->Items.size() || y >= this->Items[0].size() || newx >= this->Items.size() || newy >= this->Items[0].size())
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
    for(int i = 0; i < this->Items.size(); i++)
    {
        for(int j = 0; j < this->Items[0].size(); j++)
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
    ItemsNames.resize(this->Items[0].size()*this->Items.size());
    for (int x = 0; x < this->Items.size(); x++)
    {
        for(int y = 0; y < this->Items[0].size(); y++)
        {
            if(this->Items[x][y])
            {
                ItemsNames[x*this->Items.size()+y] = this->Items[x][y]->getName();
            }
        }
    }

    DisplayCells::DisplayFullCells(this->Items.size(), ItemsNames, this->getCurrentY(), this->getCurrentX(), 0, 24, 6);
}

bool Inventory::UpgradeItem()
{
    return this->Items[this->getCurrentX()][this->getCurrentY()]->upgrade();
}

Item** Inventory::GetRow()
{
    return this->Items[CurrentX].data();
}

void Inventory::Align()
{
    std::queue<std::pair<int, int>> FreeCordinates;

    for(int row = 0; row < this->Items.size(); row++)
    {
        for(int col = 0; col < this->Items[col].size(); col++)
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
    for(int row = 0; row < this->Items.size(); row++)
    {
        for(int col = 0; col < this->Items[col].size(); col++)
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
    if(newX >= this->Items.size()|| newY >= this->Items[0].size())
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
    return this->Items.size();
}

unsigned int Inventory::GetRowsMaxSize() const
{
    return this->Items[0].size();
}

unsigned int Inventory::getCurrentX() const
{
    return CurrentX;
}

unsigned int Inventory::getCurrentY() const
{
    return CurrentY;
}

void Inventory::SaveInventory()
{
    nlohmann::json SaveFile = nlohmann::json::array();

    for(int i = 0; i < this->Items.size(); i++)
    {
        nlohmann::json SaveFileRow = nlohmann::json::array();
        for(int j = 0; j < this->Items[i].size(); j++)
        {
            if(this->Items[i][j])
            {
                SaveFileRow.push_back(this->Items[i][j]->to_json());
            }
            else
            {
                SaveFileRow.push_back(NULL);
            }
        }
        SaveFile.push_back(SaveFileRow);
    }

    std::ofstream outputFile("saves/Inventory.json");
    outputFile << SaveFile;
    outputFile.close();
}

void Inventory::LoadInventory()
{
    //to do, finish laading
    /*
    nlohmann::json LoadedInventory;

    // Read from a file
    std::ifstream inputFile("saves/data.json");
    if (inputFile.is_open()) {
        inputFile >> LoadedInventory;
        inputFile.close();
    } else {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }

    for(int i = 0; i < this->Items.size(); i++)
    {
        for(int j = 0; j < this->Items[i].size(); j++)
        {
            Item* item;
            if(!LoadedInventory[i][j])
            {
                continue;
            }
            else
            {
                if(this->Items[i][j])
                {
                    delete this->Items[i][j];
                    this->Items[i][j] = nullptr;
                }
                Attribute attribute = Attribute(LoadedInventory[i][j]["attribute"]["mana"], LoadedInventory[i][j]["attribute"]["health"], LoadedInventory[i][j]["attribute"]["energy"], LoadedInventory[i][j]["attribute"]["defense"], LoadedInventory[i][j]["attribute"]["damage"]);
                switch(std::atoi(std::string(LoadedInventory[i][j]["name"]).data()))
                {
                    case std::atoi("sword"):
                    {
                        item = new Weapon(LoadedInventory[i][j]["level"], LoadedInventory[i][j]["name"], LoadedInventory[i][j]["rarity"], LoadedInventory[i][j]["durability"], attribute.getDamage());
                    }
                }
            }
        }
    }
    */
}

Inventory::~Inventory()
{
    this->SaveInventory();
    for(int i = 0; i < this->Items.size(); i++)
    {
        for(int j = 0; j < this->Items[i].size(); j++)
        {
            if(this->Items[i][j])
            {
                delete this->Items[i][j];
            }
        }
    }
}
