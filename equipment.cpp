#include "equipment.hpp"
#include <vector>
#include "displaycells.hpp"

Equipment::Equipment(Item** EquipmentItems) : EquipmentItems(EquipmentItems)
{

}

Item* Equipment::GetItem(int index)
{
    return !this->EquipmentItems[index] ? nullptr : this->EquipmentItems[index];
}
