#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP
#include "item.hpp"

class Equipment
{
public:
    Equipment(std::vector<Item*>* EquipmentItems);

    //void DisplayEquipment(int x, int y);
    Item* GetItem(int index);
private:
    std::vector<Item*>* EquipmentItems;
};

#endif // EQUIPMENT_HPP
