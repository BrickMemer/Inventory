#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>

class Enemy
{
private:
    std::string name;
    int level, hp, damage, defense, xp;
public:
    Enemy();
    Enemy(int level, const std::string &name, int hp, int damage, int defense, int xp);


    std::string getName() const;
    void setName(const std::string &newName);
    int getLevel() const;
    void setLevel(int newLevel);
    int getHp() const;
    void setHp(int newHp);
    int getDamage() const;
    void setDamage(int newDamage);
    int getDefense() const;
    void setDefense(int newDefense);
    int getXp() const;
    void setXp(int newXp);
};

#endif // ENEMY_H
