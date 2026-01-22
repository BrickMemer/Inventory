#include "attribute.h"
Attribute::Attribute() {
    mana = 0;
    health = 0;
    energy = 0;
    defense = 0;
    damage = 1;
}

Attribute::Attribute(int mana, int health, int energy, int defense, int damage):
    mana{mana},
    health{health},
    energy{energy},
    defense{defense},
    damage{damage}
{

}


int Attribute::getMana() const
{
    return mana;
}

void Attribute::setMana(int newMana)
{
    mana = newMana;
}

int Attribute::getHealth() const
{
    return health;
}

void Attribute::setHealth(int newHealth)
{
    health = newHealth;
}

int Attribute::getEnergy() const
{
    return energy;
}

void Attribute::setEnergy(int newEnergy)
{
    energy = newEnergy;
}

int Attribute::getDefense() const
{
    return defense;
}

void Attribute::setDefense(int newDefense)
{
    defense = newDefense;
}

int Attribute::getDamage() const
{
    return damage;
}

void Attribute::setDamage(int newDamage)
{
    damage = newDamage;
}
