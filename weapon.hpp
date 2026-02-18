#ifndef WEAPON_H
#define WEAPON_H
#include "item.hpp"

class Weapon: public Item
{
public:
    Weapon();
    Weapon(const std::string &name, int maxQuantity, int price, int damage);

    //Getters and Setters
    int getDamage() const;
    void setDamage(int newDamage);

    void use() override;
};

#endif // WEAPON_H
