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
}

Item::Item(const std::string &name, int maxQuantity, int price) :
    name(name),
    level(1),
    durability(100),
    maxQuantity(maxQuantity)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,1000);
    int randNum = dist6(rng);
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

    this->price = this->CalculatePrice(*this);
}

Item::~Item(){
    //Empty for now
}

std::string Item::getName() const
{
    return name;
}

std::string Item::getRarityName() const
{
    switch (rarity) {
    case 0:
        return "common";
        break;
    case 1:
        return "uncommon";
        break;
    case 2:
        return "rare";
        break;
    case 3:
        return "epic";
        break;
    case 4:
        return "legendary";
        break;
    case 5:
        return "mythie";
        break;
    case 6:
        return "unique";
        break;
    default:
        return "error";
        break;
    }
}

void Item::setName(const std::string &newName)
{
    name = newName;
}

Rarity Item::getRarity() const
{
    return rarity;
}

Attribute Item::getAttribute() const
{
    return attribute;
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
    std::cout << "Info for " << name << "\n";
    std::cout << "1. Level: " << level << "\n";
    std::cout << "2. Rarity: " << this->getRarityName() << "\n";
    std::cout << "3. Max Quantity: " << maxQuantity << "\n";
    std::cout << "4. Durability: " << durability << "\n";
    std::cout << "5. Price: " << price << "\n";
}

unsigned int Item::CalculatePrice(Item& ItemToCalculate)
{
    return ItemToCalculate.getDurability() + ItemToCalculate.getAttribute().getDamage() + ItemToCalculate.getAttribute().getDefense() + ItemToCalculate.getAttribute().getEnergy() + ItemToCalculate.getAttribute().getHealth() + ItemToCalculate.getAttribute().getMana() + (ItemToCalculate.getLevel() * 10);
}
