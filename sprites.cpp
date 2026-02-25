#include "sprite.hpp"

Sprite::Sprite(const std::string& SpriteName)
{
    this->LoadSprite(SpriteName);
}

void Sprite::LoadSprite(const std::string& SpriteName)
{
    std::ifstream file("sprites/"+SpriteName+".txt");
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + SpriteName);
    }

    std::string line;
    while (std::getline(file, line))
    {
        SpriteData.push_back(line);
    }
    file.close();
}

void Sprite::ReverseSprite()
{
    for(int i = 0; i < SpriteData.size();)
    {
            // Initialize left to the beginning
    // and right to the end
        int left = 0, right = SpriteData[i].size() - 1;
  
    // Iterate till left is less than right
        while(left < right) 
        {
      
        // Swap the elements at left 
        // and right position
            std::swap(SpriteData[i][left], SpriteData[i][right]);

            if(SpriteData[i][left] == '/')
            {
                SpriteData[i][left] = 92;
            }
            else if(SpriteData[i][left] == 92)
            {
                SpriteData[i][left] = '/';
            }
            if(SpriteData[i][right] == '/')
            {
                SpriteData[i][right] = 92;
            }
            else if(SpriteData[i][right] == 92)
            {
                SpriteData[i][right] = '/';
            }
      
        // Increment the left pointer
            left++;
      
        // Decrement the right pointer
            right--;
        }
        i++;
    }
}

std::string Sprite::GetLineOfSprite(int index) const
{
    return SpriteData[index];
}

unsigned int Sprite::GetSpriteHeight() const
{
    return SpriteData[0].size();
}
