#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "inventory.hpp"
#include "weapon.hpp"
#include <algorithm>
#include <thread>
#include <future>

class player
{
private:
    unsigned int Money = 0;
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
    void ResetCorrdinates();
    bool GetInfo();
    Item* GetItem();
    void RemoveItem();

    unsigned int getMoney() const;
    void AddMoney(unsigned int MoneyToAdd);
    void SubstractMoney(unsigned int AmountOfMoneyToSubstract);
};

#endif // PLAYER_HPP
