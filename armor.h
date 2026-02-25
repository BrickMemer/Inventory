#ifndef ARMOR_H
#define ARMOR_H
#include "item.hpp"
class Armor : public Item
{
public:
    Armor();
    Armor(int level, const std::string &name, Rarity rarity,int durability, int defense);
    void SetDefense(int newDefense);
    void use();
};

#endif // ARMOR_H
