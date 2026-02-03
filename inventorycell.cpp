#include "inventorycell.h"

int InventoryCell::getQuantity() const
{
    return quantity;
}

void InventoryCell::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

Item *InventoryCell::getItem() const
{
    return item;
}

void InventoryCell::setItem(Item *newItem)
{
    item = newItem;
}

InventoryCell::InventoryCell() {
    this->item = nullptr;
    this->quantity = 0;
}

InventoryCell::~InventoryCell()
{
    if(item == nullptr){
        return;
    }
    delete item;
}
