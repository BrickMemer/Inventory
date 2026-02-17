#ifndef STORE_HPP
#define STORE_HPP

#include "inventory.hpp"
#include "weapon.hpp"
#include "random"
#include "player.hpp"

class Store
{
private:
    const unsigned short StoreSize = 4;
    Inventory StoreInventory;

    void FillStore();
    Item* AddNewItem();
    unsigned short CurrentX = 0;
public:
    Store();

    void GetInfo();
    void Display();
    void MoveRightOrLeft(bool RightOrLeft);
    bool BuyItem(player& CurrentPlayer);
};

#endif // STORE_H
