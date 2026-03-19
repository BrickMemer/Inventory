#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "inventory.hpp"
#include "weapon.hpp"
#include "equipment.hpp"
#include <algorithm>

class player
{
private:
    int health = 100;
    int defense = 0;
    int damage = 0;
    unsigned int Money = 250;
    Inventory PlayerInventory;
    Equipment PlayerEquipment;
public:
    player();

    void DisplayInventory(); // Now calls Inventory::DisplayInventory with PlayerEquipment

    bool AddItem(Item* item);
    void AlignItems();
    void ClearItems();
    bool MoveX(bool UpOrDown);
    bool MoveY(bool LeftOrRight);
    bool GetInfo();
    Item* GetItem();
    void RemoveItem();
    void ResetCorrdinates();
    bool MoveToEquipment();
    bool UpgradeItem();
    void Death();
    void Revive();
    unsigned int getMoney() const;
    void AddMoney(unsigned int MoneyToAdd);
    void SubstractMoney(unsigned int MoneyToSubstract);
    int getHealth() const;
    void setHealth(int newHealth);
    int getDefense() const;

    // Equipment system methods
    bool equipItem(EquipmentSlot slot, Item* item);
    Item* unequipItem(EquipmentSlot slot);
    void recalculateAttributes();
    int Attack() const;
    void setDamage();
    void RecalculateStats();
    void LoadInventory();

    ~player();
};

#endif // PLAYER_HPP
