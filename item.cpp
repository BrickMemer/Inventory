#include "item.hpp"
#include <random>

#define COMMON_PROCENT 600 // 60%
#define UNCMMON_PROCENT 800 // 20%
#define RARE_PROCENT 950 // 15%
#define EPIC_PROCENT 990 // 4%
#define LEGENDARY_PROCENT 998 // 0,8%
#define MYTHIE_PROCENT 1000 // 0,2%


Item::Item() {
    this->name = "Stick";
    this->level = 1;
    this->rarity = common;
    this->durability = 100;
    this->maxQuantity = 64;
    this->price = 0;
    this->attribute = new Attribute();
}

Item::Item(const std::string &name, int maxQuantity, int price) :
    name(name),
    level(1),
    durability(100),
    maxQuantity(maxQuantity),
    attribute(new Attribute())
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,1000);
    int randNum = dist6(rng);
    if(randNum < COMMON_PROCENT){
        rarity = common;
        this->price = price;
    }
    if(randNum >= COMMON_PROCENT && randNum < UNCMMON_PROCENT){
        rarity = uncommon;
        this->price = price + 5;
    }
    if(randNum >= UNCMMON_PROCENT && randNum < RARE_PROCENT){
        rarity = rare;
        this->price = price + 10;
    }
    if(randNum >= RARE_PROCENT && randNum < EPIC_PROCENT){
        rarity = epic;
        this->price = price * 2;
    }
    if(randNum >= EPIC_PROCENT && randNum < LEGENDARY_PROCENT){
        rarity = legendary;
        this->price = price * 4;
    }
    if(randNum >= LEGENDARY_PROCENT && randNum < MYTHIE_PROCENT){
        rarity = mythie;
        this->price = price * 10;
    }
}

Item::~Item(){
    delete attribute;
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

void Item::getInfo()
{
    std::string nameOfRarity;
    switch (rarity) {
    case 0:
        nameOfRarity = "common";
        break;
    case 1:
        nameOfRarity = "uncommon";
        break;
    case 2:
        nameOfRarity = "rare";
        break;
    case 3:
        nameOfRarity = "epic";
        break;
    case 4:
        nameOfRarity = "legendary";
        break;
    case 5:
        nameOfRarity = "mythie";
        break;
    default:
        nameOfRarity = "unique";
        break;
    }
    std::cout << "Info for " << name << "\n";
    std::cout << "1. Level: " << level << "\n";
    std::cout << "2. Rarity: " << nameOfRarity << "\n";
    std::cout << "3. Max Quantity: " << maxQuantity << "\n";
    std::cout << "4. Durability: " << durability << "\n";
    std::cout << "5. Price: " << price << "\n";
}
