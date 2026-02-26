#ifndef ARMOR_H
#define ARMOR_H
#include "item.hpp"
class Armor : public Item
{
public:
    Armor();
    Armor(int level, const std::string &name, Rarity rarity,int durability, int defense);
    void use() override;
    bool upgrade() override;

    void SetDefense(int NewDefense);
    int GetDefense();
};

#endif // ARMOR_H
