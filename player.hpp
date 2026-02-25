#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "inventory.hpp"
#include "weapon.hpp"
#include <algorithm>

class player
{
private:
    int health = 100;
    int defense = 0;
    int damage = 0;
    unsigned int Money = 200;
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
    void Death();
    void Revive();
    unsigned int getMoney() const;
    void AddMoney(unsigned int MoneyToAdd);
    void SubstractMoney(unsigned int MoneyToSubstract);
    int getHealth() const;
    void setHealth(int newHealth);
    int getDefense() const;
    void setDefense();
    int Attack() const;
    void setDamage();
    void RecalculateStats();
};

#endif // PLAYER_HPP
