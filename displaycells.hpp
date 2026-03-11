#ifndef DISPLAYCELLS_HPP
#define DISPLAYCELLS_HPP
#include <vector>
#include "Displaycell.hpp"

class DisplayCells
{
public:
    static void DisplayFullCells(int rows, std::vector<std::string> ArrayOfTextToDisplay, int SelectedColumn, int SelectedRow);
};

#endif // DISPLAYCELLS_H
