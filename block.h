#ifndef BLOCK_H
#define BLOCK_H
#include "item.hpp"

class Block: public Item
{
public:
    Block();
    Block(const std::string &name, int maxQuantity, int price);

    void use();
};

#endif // BLOCK_H
