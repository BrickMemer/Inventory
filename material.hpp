#ifndef MATERIAL_H
#define MATERIAL_H
#include "item.hpp"

class Material: public Item
{
public:
    Material();
    Material(int level, std::string name, Rarity rarity, int maxQuantity);
    Material(const nlohmann::json& SavedMaterial);

    void use() override;
};

#endif // MATERIAL_H
