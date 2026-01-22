#include "block.h"

Block::Block() {}

Block::Block(const std::string &name, int maxQuantity, int price): Item::Item(name, maxQuantity, price)
{

}

void Block::use()
{
    std::cout << "Place a " << name << std::endl;
}
