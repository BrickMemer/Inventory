#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "inventory.hpp"
#include "weapon.h"
#include <algorithm>
#include <thread>
#include <future>

class player
{
private:
    unsigned int CurrentX = 0;
    unsigned int CurrentY = 0;
    Inventory PlayerInventory;
    std::mutex mtx;
public:
    player();

    void DisplayInventory();

    bool AddItem(Item* Item);
    void AlignItems();
    void ClearItems();
    bool MoveX(bool RightOrLeft);
    bool MoveY(bool UpOrDown);
};

#endif // PLAYER_HPP
