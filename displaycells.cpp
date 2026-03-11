#include "displaycells.hpp"
#include <iostream>
#include <cmath>

void DisplayCells::DisplayFullCells(int rows, std::vector<std::string> ArrayOfTextToDisplay, int SelectedColumn, int SelectedRow)
{
    for(int row = 0; row < rows; row++)
    {
        for(int level = 0; level < 6; level++)
        {
            for(int column = 0; column < std::floor(ArrayOfTextToDisplay.size() / rows); column++)
            {
                std::cout << DisplayCell::display(level, SelectedColumn*(SelectedRow+1)==column+row, ArrayOfTextToDisplay[column]);
            }
            std::cout << '\n';
        }
    }
}
