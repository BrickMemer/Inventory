#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "item.hpp"
#include "Displaycell.hpp"
#include <iostream>
#include <vector>

class Inventory
{
private:
    std::vector<std::vector<Item*>> Items;
    unsigned int CurrentX = 0;
    unsigned int CurrentY = 0;
public:
    Inventory(unsigned int Rows, unsigned int Columns);
    Inventory(nlohmann::json SavedInvetory);

    bool SetItem(Item* item);
    Item* GetItem();
    bool Remove();
    Item* Drop();
    bool AddItem(Item* item);
    bool MoveOrSwap(int x,int y,int newx,int newy);
    bool GetInfo();
    void DisplayInventory();
    void Align();
    void Clear();
    void ResetCorrdinates();
    bool UpgradeItem();
    std::vector<Item*>* GetRow();
    bool SetCorrdinates(const unsigned int newX, const unsigned int newY);
    unsigned int GetRowsMaxSize() const;
    unsigned int GetColumnsMaxSize() const;

    void SaveInventory();
    void LoadInventory();

    ~Inventory();
    unsigned int getCurrentX() const;
    unsigned int getCurrentY() const;
};

#endif // INVENTORY_HPP
