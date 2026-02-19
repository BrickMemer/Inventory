#ifndef MATERIAL_H
#define MATERIAL_H
#include "item.hpp"

class Material: public Item
{
public:
    Material();

    void use() override;
};

#endif // MATERIAL_H
