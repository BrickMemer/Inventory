#ifndef SWORD_H
#define SWORD_H
#include "item.hpp"

class Sword: public Item
{
protected:
    int damage;
public:
    Sword();
    Sword(const std::string &name, int price, int damage);

    //Getters and Setters
    int getDamage() const;
    void setDamage(int damage);

    void use() override;
};

#endif // SWORD_H
