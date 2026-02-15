#include "weapon.hpp"

Weapon::Weapon() {
    this->level = 1;
    this->name = "Sword";
    this->maxQuantity = 1;
    this->rarity = common;
    this->durability = 100;
    this->price = 2;
    this->attribute.setDamage(5);
}

Weapon::Weapon(const std::string &name,int maxQuantity, int price, int damage) : Item(name, maxQuantity, price)
{
    attribute.setDamage(damage);
}
void Weapon::use()
{
    std::cout << "Attack!! " << std::endl;
    std::cout << "Damage : " << attribute.getDamage() << " Hp" << std::endl;
    durability-=1;
}

int Weapon::getDamage() const
{
    return this->attribute.getDamage();
}

void Weapon::setDamage(int newDamage)
{
    this->attribute.setDamage(newDamage);
}
