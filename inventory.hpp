#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "item.hpp"
#include <iostream>
#include <queue>
#include <shared_mutex>
#include <mutex>

class Inventory
{
private:
    unsigned int Rows;
    unsigned int Columns;
    Item*** Items;
    unsigned int CurrentRow;
    unsigned int CurrentColumns;
    std::shared_mutex Shared_mtx;
public:
    Inventory(unsigned int Rows, unsigned int Columns);

    bool Set(Item* Item, const unsigned int x, const unsigned int y);
    Item* Get(const unsigned int x, const unsigned int y);
    bool Remove(const unsigned int x, const unsigned int y);
    Item* Drop(const unsigned int x, const unsigned int y);
    bool AddItem(Item* Item);
    bool MoveOrSwap(int x,int y,int newx,int newy);
    bool GetInfo(const unsigned int x, const unsigned int y);
    void DisplayInventory(const unsigned int x,const unsigned int y);
    void Align();
    void Clear();
    unsigned int GetRowsMaxSize();
    unsigned int GetColumnsMaxSize();

    ~Inventory();
};

#endif // INVENTORY_HPP
