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

std::string InventoryCell::display(int level)
{
    std::string NameToDisplay;
    unsigned short SpaceBetween = 24;
    switch (level) {
    case 0:
        NameToDisplay.append(" +");
        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append("-");
        }
        NameToDisplay.append("+ ");
        break;
    case 1:
        NameToDisplay.append(" |");
        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append(" ");
        }
        NameToDisplay.append("| ");
        break;
    case 2:
        NameToDisplay.append(" |");
        if(this->item == nullptr){
            for (int i = 0; i < SpaceBetween; ++i) {
                NameToDisplay.append(" ");
            }
        }else{
            short MiddleSpot = static_cast<short>((SpaceBetween - item->getName().length()) / 2);
            for(size_t z = 0; z < MiddleSpot; z++)
            {
                NameToDisplay.append(" ");
            }
            NameToDisplay.append(item->getName());
            for(size_t z = 0; z < MiddleSpot; z++)
            {
                NameToDisplay.append(" ");
            }
            if(item->getName().length() % 2 != 0)
            {
                NameToDisplay.append(" ");
            }
        }
        NameToDisplay.append("| ");
        break;
    case 3:
        NameToDisplay.append(" |");
        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append(" ");
        }
        NameToDisplay.append("| ");
        break;
    case 4:
        NameToDisplay.append(" +");
        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append("-");
        }
        NameToDisplay.append("+ ");
        break;
    default:
        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append(" ");
        }
        break;
    }
    return NameToDisplay;
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
