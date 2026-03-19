#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP
#include "item.hpp"
#include <map>
#include <string>
#include <nlohmann/json.hpp>

enum class EquipmentSlot {
    Weapon,
    Armor,
};

class Equipment {
public:
    Equipment();

    bool equip(EquipmentSlot slot, Item* item);
    Item* unequip(EquipmentSlot slot);
    Item* get(EquipmentSlot slot) const;

    std::map<EquipmentSlot, Item*> getAll() const;

    // Display equipment in a beautiful way
    void DisplayEquipment() const;
    ~Equipment();
private:
    std::map<EquipmentSlot, Item*> slots;
};

#endif // EQUIPMENT_HPP
