#ifndef STORE_HPP
#define STORE_HPP

#include "inventory.hpp"
#include "weapon.hpp"
#include "armor.h"
#include "material.h"
#include "random"
#include "player.hpp"

class Store
{
private:
    const unsigned short StoreSize = 4;
    Inventory StoreInventory;

    void FillStore();
    Item* AddNewItem(int index);
public:
    Store();

    void GetInfo();
    void DisplayStore();
    void MoveY(bool LeftOrRight);
    bool BuyItem(player& CurrentPlayer);
    static void SellItem(player& CurrentPlayer);
};

#endif // STORE_H
