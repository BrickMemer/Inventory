#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "inventory.hpp"
#include <algorithm>
#include <thread>
#include <future>

class player
{
private:
    size_t CurrentX = 0;
    size_t CurrentY = 0;
    Inventory PlayerInventory;
    bool MoveX(bool RightOrLeft);
    bool MoveY(bool UpOrDown);
    std::mutex mtx;
public:
    player(std::shared_mutex& mtx);

    void DisplayInventory();

    bool AddItem(Item* Item);
    void AlignItems();
};

#endif // PLAYER_HPP
