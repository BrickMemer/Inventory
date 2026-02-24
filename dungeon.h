#ifndef DUNGEON_H
#define DUNGEON_H
#include "floor.h"

class dungeon
{
    int level, curentFloor;
    std::string name;
    std::vector<floor> floors;

public:
    dungeon();
    dungeon(int level, const std::string name, int size);

    int AttackToPlayer();

};

#endif // DUNGEON_H
