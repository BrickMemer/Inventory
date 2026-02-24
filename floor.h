#ifndef FLOOR_H
#define FLOOR_H
#include "enemy.h"
#include <vector>
#include <cstdlib>

class floor
{
private:
    int level;
    std::vector<Enemy> enemies;

public:
    floor();
    floor(int level);

    int getLevel() const;
    void setLevel(int newLevel);
    std::vector<Enemy> getEnemies() const;
    void setEnemies(const std::vector<Enemy> &newEnemies);

    Enemy getRandEnemy();
};

#endif // FLOOR_H
