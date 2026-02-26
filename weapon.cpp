#include "weapon.hpp"

Weapon::Weapon() {
    this->level = 1;
    this->name = "Sword";
    this->maxQuantity = 1;
    this->rarity = common;
    this->durability = 100;
    this->attribute.setDamage(5);
    this->price = this->CalculatePrice(*this);
    this->isCanEquip = true;
}

Weapon::Weapon(const std::string &name, int price, int damage) : Item(1, name, common, 1, 100, true)
{
    attribute.setDamage(damage);
    this->isCanEquip = true;
}

Weapon::Weapon(int level, const std::string &name, Rarity rarity, int durability, int damage): Item(level, name, rarity, 1, durability, true)
{
    this->attribute.setDamage(damage);
}


void Weapon::use()
{
    std::cout << "Attack!! " << std::endl;
    std::cout << "Damage : " << attribute.getDamage() << " Hp" << std::endl;
    durability-=10;
}

bool Weapon::upgrade()
{
    bool Result = Item::upgrade();
    if(Result == false)
    {
        return false;
    }
    else
    {
        //std::cout << this->getDamage() << '\n';
        this->setDamage((int)this->getDamage() + 10);
        //std::cout << this->getDamage() << '\n';
        return true;
    }
}

int Weapon::getDamage() const
{
    return this->attribute.getDamage();
}

void Weapon::setDamage(int newDamage)
{
    this->attribute.setDamage(newDamage);
}
