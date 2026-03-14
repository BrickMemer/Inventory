#ifndef DISPLAYCELL_H
#define DISPLAYCELL_H
#include <string>

class DisplayCell
{
public:
    static std::string display(const int& level, const bool& isSelected, const std::string& TextInside, const int& CellWidth, const int& CellHeight);
};

#endif // DISPLAYCELL_H
