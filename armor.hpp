#ifndef ARMOR_H
#define ARMOR_H
#include "item.hpp"
class Armor : public Item
{
public:
    Armor();
    Armor(int level, const std::string &name, Rarity rarity,int durability, int defense);
    void use() override;
};

#endif // ARMOR_H
