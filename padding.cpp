#include "padding.hpp"
#include <iostream>
#include <string>

void Padding::PaddingLeft(int amount)
{
    std::string PaddingText;
    PaddingText.resize(amount);
    std::fill(PaddingText.begin(), PaddingText.end(), ' ');
    std::cout << PaddingText;
}
