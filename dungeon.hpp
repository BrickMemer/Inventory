#ifndef DUNGEON_H
#define DUNGEON_H

#include<vector>
#include "floor.hpp"
#include "player.hpp"

class dungeon
{
    int level, curentFloor = 0;
    int Size;
    std::vector<Floor> floors;
    void SimulateFight(player& CurrentPlayer);
public:
    dungeon();
    dungeon(int level, int size);

    void GenerateDungeon();
    void NewFloor();
    void DisplayFight(const int& CurrentChoice);
    void PlayerAttack(int damage, int index);
    bool MoveForward();
    Floor& getFloor();
};

#endif // DUNGEON_H
