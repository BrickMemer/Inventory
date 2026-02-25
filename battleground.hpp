#ifndef BATTLEGROUND_HPP
#define BATTLEGROUND_HPP
#include "sprite.hpp"

class BattleGround
{
public:
    void AddSprite(const std::string& SpriteName);
    int DrawBattleGround() const;
    
    ~BattleGround();
private:
    std::vector<Sprite*> Sprites;
};

#endif
