#include "equipment.hpp"
#include <fstream>
// Modern and beautiful equipment display
void Equipment::DisplayEquipment() const {
    const char* top =    "+---------------------------------------+";
    const char* bottom = "+---------------------------------------+";
    const char* sep =    "|---------------------------------------|";
    std::cout << "\n" << top << std::endl;
    std::cout << "|          \033[1;36mEQUIPMENT SLOTS\033[0m              |" << std::endl;
    std::cout << sep << std::endl;

    // Always show all slots, even if empty
    for (int i = 0; i <= (int)EquipmentSlot::Armor; ++i) {
        EquipmentSlot slot = static_cast<EquipmentSlot>(i);
        std::string slotName;
        switch (slot) {
            case EquipmentSlot::Weapon: slotName = "Weapon"; break;
            case EquipmentSlot::Armor: slotName = "Armor"; break;
            default: slotName = "Unknown"; break;
        }
        std::cout << "|  [" << slotName << "] ";
        auto it = slots.find(slot);
        if (it != slots.end() && it->second) {
            // Color by rarity (simple: legendary=yellow, epic=magenta, rare=blue, else=white)
            std::string color;
            std::string rarity = it->second->getRarityName();
            if (rarity == "legendary") color = "\033[1;33m";
            else if (rarity == "epic") color = "\033[1;35m";
            else if (rarity == "rare") color = "\033[1;34m";
            else color = "\033[1;37m";
            std::cout << color << it->second->getName() << "\033[0m";
            std::cout << "  (Lvl " << it->second->getLevel() << ", " << rarity << ")";
        } else {
            std::cout << "\033[1;30mEmpty\033[0m";
        }
        // Fill to right border
        int len = 10 + slotName.size();
        if (it != slots.end() && it->second) {
            len += (int)it->second->getName().size() + 9 + (int)it->second->getRarityName().size();
        } else {
            len += 5;
        }
        for (; len < 36; ++len) std::cout << ' ';
        std::cout << "|" << std::endl;
        if (i != (int)EquipmentSlot::Armor) std::cout << sep << std::endl;
    }
    std::cout << bottom << "\n" << std::endl;
}


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

Equipment::~Equipment()
{
    nlohmann::json EquipmentSave = nlohmann::json::array();
    for (auto const& x : this->slots)
    {
        if(x.second)
        {
            EquipmentSave.push_back(std::make_pair(x.first, x.second->to_json()));
        }
        else
        {
            EquipmentSave.push_back(std::make_pair(x.first, NULL));
        }
    }

    std::ofstream outputFile("saves/Equipment.json");
    outputFile << EquipmentSave;
    outputFile.close();
}