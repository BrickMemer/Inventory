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
    Attribute* attribute;
    int maxQuantity;
    int price;
public:
    Item();
    Item(const std::string &name, int maxQuantity, int price);
    ~Item();

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

    void virtual use() = 0;
    void getInfo();
};

#endif // ITEM_HPP
