#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "inventory.hpp"
#include "weapon.hpp"
#include <algorithm>

class player
{
private:
    unsigned int Money = 0;
    Inventory PlayerInventory;
public:
    player();

    void DisplayInventory();

    bool AddItem(Item* item);
    void AlignItems();
    void ClearItems();
    bool MoveX(bool UpOrDown);
    bool MoveY(bool LeftOrRight);
    bool GetInfo();
    Item* GetItem();
    void RemoveItem();
    void ResetCorrdinates();

    unsigned int getMoney() const;
    void AddMoney(unsigned int MoneyToAdd);
    void SubstractMoney(unsigned int MoneyToSubstract);
};

#endif // PLAYER_HPP
