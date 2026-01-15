#include "item.hpp"
#include <time.h>

#define COMMON_PROCENT 60
#define UNCMMON_PROCENT 80
#define RARE_PROCENT 90
#define EPIC_PROCENT 96
#define LEGENDARY_PROCENT 98
#define MYTHIE_PROCENT 100


Item::Item() {}

Item::Item(const std::string &name, int maxQuantity, int price) : name(name),
    level(0),
    durability(100),
    maxQuantity(maxQuantity),
    price(price)
{
    srand(time(NULL));
    int randNum = rand() % 101;
    if(randNum < COMMON_PROCENT){
        rarity = common;
    }
    if(randNum >= COMMON_PROCENT && randNum < UNCMMON_PROCENT){
        rarity = uncommon;
    }
    if(randNum >= UNCMMON_PROCENT && randNum < RARE_PROCENT){
        rarity = rare;
    }
    if(randNum >= RARE_PROCENT && randNum < EPIC_PROCENT){
        rarity = epic;
    }
    if(randNum >= EPIC_PROCENT && randNum < LEGENDARY_PROCENT){
        rarity = legendary;
    }
    if(randNum >= LEGENDARY_PROCENT && randNum < MYTHIE_PROCENT){
        rarity = mythie;
    }
}


std::string Item::getName() const
{
    return name;
}

void Item::setName(const std::string &newName)
{
    name = newName;
}

Rarity Item::getRarity() const
{
    return rarity;
}

void Item::setRarity(Rarity newRarity)
{
    rarity = newRarity;
}

int Item::getLevel() const
{
    return level;
}

void Item::setLevel(int newLevel)
{
    level = newLevel;
}

int Item::getDurability() const
{
    return durability;
}

void Item::setDurability(int newDurability)
{
    durability = newDurability;
}

int Item::getMaxQuantity() const
{
    return maxQuantity;
}

void Item::setMaxQuantity(int newMaxQuantity)
{
    maxQuantity = newMaxQuantity;
}

int Item::getPrice() const
{
    return price;
}

void Item::setPrice(int newPrice)
{
    price = newPrice;
}
