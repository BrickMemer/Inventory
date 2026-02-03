#ifndef INVENTORYCELL_H
#define INVENTORYCELL_H
#include "item.hpp"

class InventoryCell
{
private:
    int quantity;
    Item* item;
public:
    InventoryCell();
    ~InventoryCell();



    void display(int level);
    int getQuantity() const;
    void setQuantity(int newQuantity);
    Item *getItem() const;
    void setItem(Item *newItem);
};

#endif // INVENTORYCELL_H
