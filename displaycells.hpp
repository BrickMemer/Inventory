#ifndef DISPLAYCELLS_HPP
#define DISPLAYCELLS_HPP
#include <vector>
#include <string>

class DisplayCells
{
public:
    static void DisplayFullCells(const int& rows, const std::vector<std::string>& ArrayOfTextToDisplay, const int& SelectedColumn, const int& SelectedRow, const int& PaddingLeftAmount, const int& CellWidth, const int& CellHeight);
};

#endif // DISPLAYCELLS_H
