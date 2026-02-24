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

void BattleGround::DrawBattleGround()
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
}

BattleGround::~BattleGround()
{
    for (auto sprite : this->Sprites)
    {
        delete sprite;
    }
}
