#ifndef DISPLAYCELLS_HPP
#define DISPLAYCELLS_HPP
#include <vector>
#include <string>

class DisplayCells
{
public:
    static void DisplayFullCells(int rows, std::vector<std::string> ArrayOfTextToDisplay, int SelectedColumn, int SelectedRow, int PaddingLeftAmuount);
};

#endif // DISPLAYCELLS_H
