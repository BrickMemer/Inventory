#ifndef FLOOR_H
#define FLOOR_H

#include <vector>

#include "orc.hpp"

class Floor
{
private:
    std::vector<Enemy*> enemies;

    void KillEnemy(unsigned int index);
public:
    Floor();
    Floor(int level);

    void MakeFloor(const int& level);
    int getLevel() const;
    void setLevel(int newLevel);
    std::vector<Enemy*> getEnemies() const;
    void setEnemies(const std::vector<Enemy*> &newEnemies);
    bool DamageEnemy(unsigned int index, int damage);

    Enemy* getRandEnemy();
};

#endif // FLOOR_H
