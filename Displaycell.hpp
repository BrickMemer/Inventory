#ifndef DISPLAYCELL_H
#define DISPLAYCELL_H
#include <string>

class DisplayCell
{
public:
    static std::string display(int level, bool isSelected, const std::string& TextInside);
};

#endif // DISPLAYCELL_H
