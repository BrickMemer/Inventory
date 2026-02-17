#include "store.hpp"

Store::Store() : StoreInventory(1, this->StoreSize)
{
    srand(time(NULL));
    this->FillStore();
}

void Store::FillStore()
{
    while(this->StoreInventory.AddItem(AddNewItem()) == true);
}

Item* Store::AddNewItem()
{
    Weapon* TempItem = new Weapon();
    unsigned short RandomChance = rand() % 7;
    switch(RandomChance)
    {
        case 0:
            TempItem->setRarity(common);
            TempItem->setDamage(1 + rand() % 11);
            TempItem->setDurability(11 + rand() % 21);
            break;
        case 1:
            TempItem->setRarity(uncommon);
            TempItem->setDamage(11 + rand() % 21);
            TempItem->setDurability(21 + rand() % 31);
            break;
        case 2:
            TempItem->setRarity(rare);
            TempItem->setDamage(21 + rand() % 31);
            TempItem->setDurability(31 + rand() % 41);
            break;
        case 3:
            TempItem->setRarity(epic);
            TempItem->setDamage(31 + rand() % 41);
            TempItem->setDurability(41 + rand() % 51);
            break;
        case 4:
            TempItem->setRarity(legendary);
            TempItem->setDamage(41 + rand() % 51);
            TempItem->setDurability(51 + rand() % 61);
            break;
        case 5:
            TempItem->setRarity(mythie);
            TempItem->setDamage(51 + rand() % 61);
            TempItem->setDurability(61 + rand() % 71);
            break;
        case 6:
            TempItem->setRarity(unique);
            TempItem->setDamage(61 + rand() % 71);
            TempItem->setDurability(71 + rand() % 81);
            break;
    };
    TempItem->setLevel(RandomChance);
    TempItem->setPrice(10 + rand() % 301);
    return std::move(TempItem);
}

void Store::Display()
{
    StoreInventory.DisplayInventory();
}

void Store::GetInfo()
{
    StoreInventory.GetInfo();
}

void Store::MoveY(bool LeftOrRight)
{
    if(LeftOrRight == true)
    {
        this->StoreInventory.SetCorrdinates(this->StoreInventory.getCurrentX(), this->StoreInventory.getCurrentY() - 1);
    }
    else
    {
        this->StoreInventory.SetCorrdinates(this->StoreInventory.getCurrentX(), this->StoreInventory.getCurrentY() + 1);
    }
}

bool Store::BuyItem(player& CurrentPlayer)
{
    Item* TempItem = this->StoreInventory.Get();
    //std::cout << (int) CurrentPlayer.getMoney() - TempItem->getPrice() << '\n';
    if(((int)CurrentPlayer.getMoney() - TempItem->getPrice()) < 0)
    {
        return false;
    }
    else if(CurrentPlayer.AddItem(TempItem) == false)
    {
        return false;
    }
    CurrentPlayer.SubstractMoney(TempItem->getPrice());
    TempItem->setPrice(Item::CalculatePrice(*TempItem));
    this->FillStore();
    return true;
}
