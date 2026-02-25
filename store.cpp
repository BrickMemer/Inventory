#include "store.hpp"

Store::Store() : StoreInventory(1, this->StoreSize)
{
    srand(time(NULL));
    this->FillStore();
}

void Store::FillStore()
{
    for(int i = 0; i < this->StoreSize; i++)
    {
        this->StoreInventory.AddItem(this->AddNewItem(i));
    };
}

Item* Store::AddNewItem(int index)
{
    Item* TempItem;
    unsigned short RandomChance = rand() % 7;
    switch(index)
    {
    case 0:
    {
        Weapon* TempWeapon = new Weapon;
        TempWeapon->setDamage((1 + 10 * RandomChance) + rand() % (11 + 10 * RandomChance));
        TempItem = TempWeapon;
        break;
    }
    case 1:
    {
        Armor* TempArmor = new Armor;
        TempArmor->SetDefense((1 + 10 * RandomChance) + rand() % (11 + 10 * RandomChance));
        TempItem = TempArmor;
        break;
    }
    case 2:
    case 3:
    {
        Material* TempMaterial = new Material;
        TempItem = TempMaterial;
    }
    };
    switch(RandomChance)
    {
        case 0:
            TempItem->setRarity(common);
            TempItem->setDurability(11 + rand() % 21);
            break;
        case 1:
            TempItem->setRarity(uncommon);
            TempItem->setDurability(21 + rand() % 31);
            break;
        case 2:
            TempItem->setRarity(rare);
            TempItem->setDurability(31 + rand() % 41);
            break;
        case 3:
            TempItem->setRarity(epic);
            TempItem->setDurability(41 + rand() % 51);
            break;
        case 4:
            TempItem->setRarity(legendary);
            TempItem->setDurability(51 + rand() % 61);
            break;
        case 5:
            TempItem->setRarity(mythie);
            TempItem->setDurability(61 + rand() % 71);
            break;
        case 6:
            TempItem->setRarity(unique);
            TempItem->setDurability(71 + rand() % 81);
            break;
    };
    TempItem->setLevel(RandomChance);
    TempItem->setPrice(10 + rand() % 301);
    return std::move(TempItem);
}

void Store::DisplayStore()
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
    Item* TempItem = this->StoreInventory.GetItem();
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
    this->StoreInventory.SetItem(nullptr);
    this->StoreInventory.AddItem(this->AddNewItem(this->StoreInventory.getCurrentY()));
    return true;
}


void Store::SellItem(player& CurrentPlayer)
{
    unsigned int ItemPrice = CurrentPlayer.GetItem()->getPrice();
    CurrentPlayer.AddMoney(ItemPrice);
    CurrentPlayer.RemoveItem();
}
