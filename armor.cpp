#include "armor.h"

Armor::Armor() {
    this->name = "Shield";
    this->maxQuantity = 1;
    this->price = 10;
    this->rarity = common;
    this->durability = 100;
    this->isCanEquip = true;
    this->attribute.setDefense(5);
}

Armor::Armor(int level, const std::string &name, Rarity rarity, int durability, int defense): Item(level, name, rarity, 1, durability, true)
{
    this->attribute.setDefense(defense);
}

void Armor::SetDefense(int NewDefense)
{
    this->attribute.setDefense(NewDefense);
}

void Armor::use()
{
    durability-=10;
}
