#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "item.hpp"
#include <iostream>
#include <queue>
#include <mutex>
#include <shared_mutex>

class Inventory
{
private:
    unsigned int Rows;
    unsigned int Columns;
    Item*** Items;
    unsigned int CurrentRow;
    unsigned int CurrentColumns;
    std::shared_mutex& shared_mtx;
public:
    Inventory(unsigned int Rows, unsigned int Columns, std::shared_mutex& shared_mtx);

    bool Set(Item* Item, const unsigned int x,const unsigned int y);
    Item* Get(const unsigned int x,const unsigned int y);
    bool Remove(const unsigned int x,const unsigned int y);
    Item* Drop(const unsigned int x,const unsigned int y);
    bool AddItem(Item* Item);
    bool MoveOrSwap(int x,int y,int newx,int newy);
    void DisplayInventory();
    void Align();
    void Clear();
    unsigned int GetRowsMaxSize();
    unsigned int GetColumnsMaxSize();

    ~Inventory();
};

#endif // INVENTORY_HPP
