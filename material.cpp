#include "material.h"

Material::Material() {
    this->name = "Stick";
    this->level = 1;
    this->rarity = common;
    this->durability = 1;
    this->maxQuantity = 64;
    this->price = 0;
    this->isCanEquip = false;
}

Material::Material(int level, std::string name, Rarity rarity, int maxQuantity) : Item(level,name, rarity, maxQuantity, 1, false)
{

}



void Material::use()
{

}
