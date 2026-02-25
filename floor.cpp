#include "floor.hpp"

Floor::Floor()
{
    this->MakeFloor(1);
}

Floor::Floor(int level)
{
    this->MakeFloor(level);
}

void Floor::MakeFloor(const int& level)
{
    for(int i = 0; i < level; i++)
    {
        this->enemies.push_back(new Orc());
    }
}

std::vector<Enemy*> Floor::getEnemies() const
{
    return enemies;
}

void Floor::setEnemies(const std::vector<Enemy*> &newEnemies)
{
    enemies = newEnemies;
}

int Floor::DamageEnemy(unsigned int index, int damage)
{
    this->enemies[index]->setHp(this->enemies[index]->getHp() - damage);
    if(this->enemies[index]->getHp() <= 0)
    {
        const int GainedMoney = this->enemies[index]->getXp();
        this->KillEnemy(index);
        return GainedMoney;
    }
    return 0;
}
void Floor::KillEnemy(unsigned int index)
{
    delete this->enemies[index];
    this->enemies[index] = nullptr;
    this->enemies.erase(this->enemies.begin() + index);
}

bool Floor::IsEmpty() const
{
    return this->enemies.size() <= 0;
}

Enemy* Floor::getRandEnemy()
{
    int index = rand() % enemies.size();
    return enemies[index];
}
