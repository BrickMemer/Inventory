#include "battleground.hpp"

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
    const int spacebetween = 16;
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < this->GetSpritesAmount(); j++)
        {
            std::cout << this->Sprites[j]->GetLineOfSprite(i);
            for(int k = 0; k < spacebetween; k++)
            {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
    const int TotalLength = this->Sprites[0]->GetLineOfSprite(0).size() + this->Sprites[1]->GetLineOfSprite(0).size() + this->Sprites[2]->GetLineOfSprite(0).size() + spacebetween * 2;
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
