#include "battleground.hpp"
#include "padding.hpp"
#include <iostream>

BattleGround::BattleGround(std::vector<std::string>& SpritesNames)
{
    for(unsigned short i = 0; i < SpritesNames.size(); i++)
    {
        this->AddSprite(SpritesNames[i]);
    }
    this->Sprites[this->Sprites.size() - 1]->ReverseSprite();
}

void BattleGround::AddSprite(const std::string& SpriteName)
{
    this->Sprites.push_back(new Sprite(SpriteName));
}

int BattleGround::DrawBattleGround() const
{
    const int spacebetween = 36;
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < this->GetSpritesAmount(); j++)
        {
            std::cout << this->Sprites[j]->GetLineOfSprite(i);
            Padding::PaddingLeft(spacebetween);
        }
        std::cout << '\n';
    }
    
    unsigned int TotalLength = spacebetween * 2;
    
    //Adds all sprites lenght
    for(auto* sprite : this->Sprites)
    {
        TotalLength += sprite->GetLineOfSprite(0).length();
    }
    
    for (int var = 0; var < TotalLength; ++var)
    {
        std::cout << '-';
    }
    
    std::cout << '\n';
    return TotalLength;
}

int BattleGround::GetSpritesAmount() const
{
    return this->Sprites.size();
}

BattleGround::~BattleGround()
{
    for (auto sprite : this->Sprites)
    {
        delete sprite;
    }
}
