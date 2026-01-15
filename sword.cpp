#include "sword.h"

Sword::Sword() {}

Sword::Sword(const std::string &name, int price, int damage):
    Item(name, 1, price),
    damage{damage}
{

}

int Sword::getDamage() const
{
    return damage;
}

void Sword::setDamage(int damage)
{
    this->damage = damage;
}

void Sword::use()
{
    std::cout << this->getDamage() ;
}
