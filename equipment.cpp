#include "equipment.hpp"
#include <vector>
#include "displaycells.hpp"

Equipment::Equipment(std::vector<Item*>* EquipmentItems) : EquipmentItems(EquipmentItems)
{

}

Item* Equipment::GetItem(int index)
{
    /*
    if (!&this->EquipmentItems[index])
    {
        return nullptr;
    }
    */
    return nullptr;
}