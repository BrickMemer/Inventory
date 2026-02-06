#include "inventorycell.h"

int InventoryCell::getQuantity() const
{
    return quantity;
}

bool InventoryCell::setQuantity(int newQuantity)
{
    if(newQuantity < 0){
        quantity = 0;
    }else{
        quantity = newQuantity;
    }
    return true;
}

Item *InventoryCell::getItem() const
{
    return item;
}

void InventoryCell::setItem(Item *newItem)
{
    item = newItem;
}

std::string InventoryCell::display(int level, bool isSelected)
{
    std::string NameToDisplay;
    unsigned short SpaceBetween = 24;
    short MiddleSpot;

    switch (level) {
    case 0:
        //Start of line
        NameToDisplay.append(" +");


        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append("-");
        }

        //End of line
        NameToDisplay.append("+ ");
        break;
    case 1:
        //Start of line
        if(isSelected){
            NameToDisplay.append(">|");
        }else {
            NameToDisplay.append(" |");
        }


        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append(" ");
        }

        //End of line
        if(isSelected){
            NameToDisplay.append("|<");
        }else {
            NameToDisplay.append("| ");
        }
        break;
    case 2:
        //Start of line
        if(isSelected){
            NameToDisplay.append(">|");
        }else {
            NameToDisplay.append(" |");
        }


        if(this->item == nullptr){
            for (int i = 0; i < SpaceBetween; ++i) {
                NameToDisplay.append(" ");
            }
        }else{
            MiddleSpot = static_cast<short>((SpaceBetween - item->getName().length()) / 2);
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

        //End of line
        if(isSelected){
            NameToDisplay.append("|<");
        }else {
            NameToDisplay.append("| ");
        }
        break;
        break;
    case 3:
        //Start of line
        if(isSelected){
            NameToDisplay.append(">|");
        }else {
            NameToDisplay.append(" |");
        }


        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append(" ");
        }

        //End of line
        if(isSelected){
            NameToDisplay.append("|<");
        }else {
            NameToDisplay.append("| ");
        }
        break;
        break;
    case 4:
        //Start of line
        if(isSelected){
            NameToDisplay.append(">|");
        }else {
            NameToDisplay.append(" |");
        }


        MiddleSpot = static_cast<short>((SpaceBetween - std::to_string(this->getQuantity()).length()) / 2);
        for(size_t z = 0; z < MiddleSpot; z++)
        {
            NameToDisplay.append(" ");
        }
        if(this->getQuantity() > 0){
            NameToDisplay.append(std::to_string(this->getQuantity()));
        }else{
            NameToDisplay.append(" ");
        }

        for(size_t z = 0; z < MiddleSpot; z++)
        {
            NameToDisplay.append(" ");
        }
        if(std::to_string(this->getQuantity()).length() % 2 != 0)
        {
            NameToDisplay.append(" ");
        }

        //End of line
        if(isSelected){
            NameToDisplay.append("|<");
        }else {
            NameToDisplay.append("| ");
        }
        break;
    case 5:
        //Start of line
        NameToDisplay.append(" +");

        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append("-");
        }

        //End of line
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
