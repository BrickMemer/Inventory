#include "player.hpp"
bool player::equipItem(EquipmentSlot slot, Item* item) {
    if (!item || !item->getIsCanEquip()) return false;
    PlayerEquipment.equip(slot, item);
    recalculateAttributes();
    return true;
}

Item* player::unequipItem(EquipmentSlot slot) {
    Item* removed = PlayerEquipment.unequip(slot);
    recalculateAttributes();
    return removed;
}

void player::recalculateAttributes() {
    this->defense = 0;
    this->damage = 0;
    for (const auto& pair : PlayerEquipment.getAll()) {
        if (pair.second) {
            this->defense += pair.second->getAttribute().getDefense();
            this->damage += pair.second->getAttribute().getDamage();
        }
    }
}
#include "player.hpp"

// Player constructor initializes inventory and equipment
// Player constructor initializes inventory and equips a default weapon
player::player() : PlayerInventory(5,5), PlayerEquipment() 
{
    this->PlayerInventory.ResetCorrdinates();
    // Weapon* defaultSword = new Weapon("Sword", 100, 10);
    // this->PlayerEquipment.equip(EquipmentSlot::Weapon, defaultSword);
    // this->recalculateAttributes();
}

unsigned int player::getMoney() const
{
    return Money;
}

void player::AddMoney(unsigned int MoneyToAdd)
{
    this->Money = this->Money + MoneyToAdd;
}

void player::SubstractMoney(unsigned int MoneyToSubstract)
{
    this->Money = this->Money - MoneyToSubstract;
}

int player::getHealth() const
{
    return health;
}

void player::setHealth(int newHealth)
{
    health = newHealth;
}

int player::Attack() const
{
    return damage;
}

bool player::UpgradeItem()
{
    if(this->Money < 150)
    {
        return false;
    }
    else
    {
        if(this->PlayerInventory.UpgradeItem())
        {
            // Update player attributes after upgrading item
            this->recalculateAttributes();
            return true;
        }
        else
        {
            return false;
        }
    }
}

void player::Death()
{
    this->PlayerInventory.Clear();
    this->Money = 250;
}

void player::Revive()
{
    this->health = 100;
}

int player::getDefense() const
{
    return defense;
}



void player::DisplayInventory()
{
    this->PlayerEquipment.DisplayEquipment();
    this->PlayerInventory.DisplayInventory();
}
bool player::MoveX(bool UpOrDown)
{
    if(UpOrDown == true)
    {
        return this->PlayerInventory.SetCorrdinates(this->PlayerInventory.getCurrentX() - 1, this->PlayerInventory.getCurrentY());
    }
    else
    {
        return this->PlayerInventory.SetCorrdinates(this->PlayerInventory.getCurrentX() + 1, this->PlayerInventory.getCurrentY());
    }
}
bool player::MoveY(bool LeftOrRight)
{
    if(LeftOrRight == true)
    {
        return this->PlayerInventory.SetCorrdinates(this->PlayerInventory.getCurrentX(), this->PlayerInventory.getCurrentY() - 1);
    }
    else
    {
        return this->PlayerInventory.SetCorrdinates(this->PlayerInventory.getCurrentX(), this->PlayerInventory.getCurrentY() + 1);
    }
}

// Move item from inventory to equipment slot (example: Weapon slot)
bool player::MoveToEquipment()
{
    Item* item = this->PlayerInventory.GetItem();
    if (!item) return false;

    // Example: move to Weapon slot if item can be equipped
    if (item->getIsCanEquip()) {
        if (this->PlayerEquipment.get(EquipmentSlot::Weapon) == nullptr) {
            this->PlayerEquipment.equip(EquipmentSlot::Weapon, item);
            this->PlayerInventory.Drop();
            this->recalculateAttributes();
            return true;
        }
    }
    return false;
}

bool player::AddItem(Item* item)
{
    if(this->PlayerInventory.AddItem(item))
    {
        // Update player attributes after adding item
        this->recalculateAttributes();
        return true;
    }
    else
    {
        return false;
    }
}

void player::ClearItems()
{
    this->PlayerInventory.Clear();
    // Update player attributes after moving item to equipment
    this->recalculateAttributes();
}

bool player::GetInfo()
{
    return this->PlayerInventory.GetInfo();
}

Item* player::GetItem()
{
    return this->PlayerInventory.GetItem();
}

void player::AlignItems()
{
    this->PlayerInventory.Align();
}

// Remove item and update player attributes
void player::RemoveItem()
{
    this->recalculateAttributes();
    this->PlayerInventory.Remove();
}

void player::ResetCorrdinates()
{
    this->PlayerInventory.ResetCorrdinates();
}

void player::LoadInventory()
{
    this->PlayerInventory.LoadInventory();
}

player::~player()
{
    //this->PlayerInventory.SaveInventory();
}
