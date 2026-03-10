#ifndef BATTLEGROUND_HPP
#define BATTLEGROUND_HPP
#include <cstdint>
#include "sprite.hpp"


class BattleGround
{
public:
    BattleGround(std::vector<std::string>& SpritesNames);
    void AddSprite(const std::string& SpriteName);
    int DrawBattleGround() const;
    int GetSpritesAmount() const;
    
    ~BattleGround();
private:
    std::vector<Sprite*> Sprites;
    const uint8_t MaxSprites = 3;
};

#endif
