#include "equipment.hpp"

Equipment::Equipment() {}

bool Equipment::equip(EquipmentSlot slot, Item* item) {
    if (!item || !item->getIsCanEquip()) return false;
    slots[slot] = item;
    return true;
}

Item* Equipment::unequip(EquipmentSlot slot) {
    auto it = slots.find(slot);
    if (it != slots.end()) {
        Item* removed = it->second;
        slots.erase(it);
        return removed;
    }
    return nullptr;
}

Item* Equipment::get(EquipmentSlot slot) const {
    auto it = slots.find(slot);
    return (it != slots.end()) ? it->second : nullptr;
}

std::map<EquipmentSlot, Item*> Equipment::getAll() const {
    return slots;
}
