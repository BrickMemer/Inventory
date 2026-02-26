#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "attribute.hpp"
enum Rarity{
    common,
    uncommon,
    rare,
    epic,
    legendary,
    mythie,
    unique
};

class Item
{
protected:
    std::string name;
    Rarity rarity;
    int level;
    int durability;
    Attribute attribute;
    int maxQuantity;
    int price;

    bool isCanEquip;
public:
    Item();
    Item(int level, const std::string &name, Rarity rarity, int maxQuantity, int durability, bool isCanEquip);
    virtual ~Item();

    //Getters and Setters
    std::string getName() const;
    void setName(const std::string &newName);
    Rarity getRarity() const;
    void setRarity(Rarity newRarity);
    std::string getRarityName() const;
    int getLevel() const;
    void setLevel(int newLevel);
    int getDurability() const;
    void setDurability(int newDurability);
    int getMaxQuantity() const;
    void setMaxQuantity(int newMaxQuantity);
    int getPrice() const;
    void setPrice(int newPrice);
    Attribute getAttribute() const;
    static unsigned int CalculatePrice(const Item& ItemToCalculate);

    void upgrade();

    void virtual use() = 0;
    void getInfo();
};

#endif // ITEM_HPP
