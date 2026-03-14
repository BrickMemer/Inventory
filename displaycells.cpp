#include "displaycells.hpp"
#include <iostream>
#include "Displaycell.hpp"
#include <cmath>
#include "padding.hpp"

void DisplayCells::DisplayFullCells(const int& rows, const std::vector<std::string>& ArrayOfTextToDisplay, const int& SelectedColumn, const int& SelectedRow, const int& PaddingLeftAmount, const int& CellWidth, const int& CellHeight)
{
    for(int row = 0; row < rows; row++)
    {
        for(int level = 0; level < CellHeight; level++)
        {
            Padding::PaddingLeft(PaddingLeftAmount);
            for(int column = 0; column < std::floor(ArrayOfTextToDisplay.size() / rows); column++)
            {
                std::cout << DisplayCell::display(level, SelectedColumn==column && SelectedRow==row, ArrayOfTextToDisplay[column+row], CellWidth, CellHeight);
            }
            std::cout << '\n';
        }
    }
}
