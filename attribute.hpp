#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <iostream>
class Attribute
{
private:
    int mana, health, energy, defense, damage;
public:
    Attribute();
    Attribute(int mana, int health, int energy , int defense, int damage);

    //Getters and Setters
    int getMana() const;
    void setMana(int newMana);
    int getHealth() const;
    void setHealth(int newHealth);
    int getEnergy() const;
    void setEnergy(int newEnergy);
    int getDefense() const;
    void setDefense(int newDefense);
    int getDamage() const;
    void setDamage(int newDamage);
};

#endif // ATTRIBUTE_H
