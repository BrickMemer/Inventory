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

    int getQuantity() const;
    bool setQuantity(int newQuantity);
    Item *getItem() const;
    void setItem(Item *newItem);

    std::string display(int level, bool isSelected);
};

#endif // INVENTORYCELL_H
