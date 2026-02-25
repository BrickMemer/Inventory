#include "battleground.hpp"
#include "sprite.hpp"
#include <string>
#include <vector>

void BattleGround::AddSprite(const std::string& SpriteName)
{
    this->Sprites.push_back(new Sprite(SpriteName));
    if(Sprites.size() == 3)
    {
        Sprites[2]->ReverseSprite();
    }
}

int BattleGround::DrawBattleGround() const
{
    const int spacebetween = 16;
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 3;j++)
        {
            switch(j)
            {
                case 0:
                    std::cout << this->Sprites[j]->GetLineOfSprite(i);
                    break;
                case 1:
                    std::cout << this->Sprites[j]->GetLineOfSprite(i);
                    break;
                case 2:
                    //this->Sprites[j]->ReverseSprite();
                    std::cout << this->Sprites[j]->GetLineOfSprite(i);
                    break;
            };
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

BattleGround::~BattleGround()
{
    for (auto sprite : this->Sprites)
    {
        delete sprite;
    }
}
