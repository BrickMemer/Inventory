#include "enemy.h"

std::string Enemy::getName() const
{
    return name;
}

void Enemy::setName(const std::string &newName)
{
    name = newName;
}

int Enemy::getLevel() const
{
    return level;
}

void Enemy::setLevel(int newLevel)
{
    level = newLevel;
}

int Enemy::getHp() const
{
    return hp;
}

void Enemy::setHp(int newHp)
{
    hp = newHp;
}

int Enemy::getDamage() const
{
    return damage;
}

void Enemy::setDamage(int newDamage)
{
    damage = newDamage;
}

int Enemy::getDefense() const
{
    return defense;
}

void Enemy::setDefense(int newDefense)
{
    defense = newDefense;
}

int Enemy::getXp() const
{
    return xp;
}

void Enemy::setXp(int newXp)
{
    xp = newXp;
}

int Enemy::Attak()
{
    return this->getDamage();
}

Enemy::Enemy():
    level(1),
    name("Slime"),
    hp(10),
    damage(1),
    defense(0),
    xp(1){
}

Enemy::Enemy(int level, const std::string &name, int hp, int damage, int defense, int xp):
    level(level),
    name(name),
    hp(hp),
    damage(damage),
    defense(defense),
    xp(xp)
{

}
