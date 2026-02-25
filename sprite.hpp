#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class Sprite {
private:
    std::vector<std::string> SpriteData;
public:
    Sprite(const std::string& SpriteName);
    void LoadSprite(const std::string& SpriteName);
    void ReverseSprite();
    std::string GetLineOfSprite(int index) const;
    unsigned int GetSpriteHeight() const;
};

#endif // SPRITE_HPP
