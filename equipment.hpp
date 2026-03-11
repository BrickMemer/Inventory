#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP
#include "item.hpp"

class Equipment
{
public:
    Equipment(Item** EquipmentItems);

    //void DisplayEquipment(int x, int y);
    Item* GetItem(int index);
private:
    Item** EquipmentItems;
};

#endif // EQUIPMENT_HPP
