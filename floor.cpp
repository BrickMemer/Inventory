#include "floor.h"

floor::floor()
{
    this->level = 1;
    this->enemies={
        Enemy()
    };
}

floor::floor(int level)
{
    this->level = level;
    switch (level) {
    case 1:
        this->enemies={
            Enemy()
        };
        break;
    default:
        this->enemies={
            Enemy(level, "Goblin", 5 * level, 10 * level, 0, 2 * level),
            Enemy(level, "Rabit", 2 * level, 4 * level, 0, 1 * level)
        };
        break;
    }
}

int floor::getLevel() const
{
    return level;
}

void floor::setLevel(int newLevel)
{
    level = newLevel;
}

std::vector<Enemy> floor::getEnemies() const
{
    return enemies;
}

void floor::setEnemies(const std::vector<Enemy> &newEnemies)
{
    enemies = newEnemies;
}

Enemy floor::getRandEnemy()
{
    int index = rand() % enemies.size();
    return enemies[index];
}


