#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <iostream>
#include <nlohmann/json.hpp>
class Attribute
{
private:
    int mana = 0, health = 0, energy = 0, defense = 0, damage = 0;
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

    nlohmann::json to_json() const;
};

#endif // ATTRIBUTE_H
