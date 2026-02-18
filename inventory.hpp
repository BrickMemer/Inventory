#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "item.hpp"
#include "inventorycell.hpp"
#include <iostream>
#include <queue>

class Inventory
{
private:
    unsigned int Rows;
    unsigned int Columns;
    InventoryCell*** Items;
    unsigned int CurrentX = 0;
    unsigned int CurrentY = 0;
public:
    Inventory(unsigned int Rows, unsigned int Columns);

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
    bool SetCorrdinates(const unsigned int newX, const unsigned int newY);
    unsigned int GetRowsMaxSize() const;
    unsigned int GetColumnsMaxSize() const;

    ~Inventory();
    unsigned int getCurrentX() const;
    unsigned int getCurrentY() const;
};

#endif // INVENTORY_HPP
