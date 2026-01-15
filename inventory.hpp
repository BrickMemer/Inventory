#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "item.hpp"

class Inventory
{
private:
    unsigned int Rows;
    unsigned int Columns;
    Item*** Items;
    unsigned int CurrentRow;
    unsigned int CurrentColumns;
public:
    Inventory(unsigned int Rows, unsigned int Columns);

    bool Set(Item* Item, const unsigned int x,const unsigned int y);
    Item* Get(const unsigned int x,const unsigned int y);
    bool Remove(const unsigned int x,const unsigned int y);
    Item* Drop(const unsigned int x,const unsigned int y);
    bool AddItem(Item* Item);
};

#endif // INVENTORY_HPP
