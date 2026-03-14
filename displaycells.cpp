#include "displaycells.hpp"
#include <iostream>
#include "Displaycell.hpp"
#include <cmath>
#include "padding.hpp"

void DisplayCells::DisplayFullCells(const int& rows, const std::vector<std::string>& ArrayOfTextToDisplay, const int& SelectedColumn, const int& SelectedRow, const int& PaddingLeftAmount, const int& CellWidth, const int& CellHeight)
{
    //ArrayOfTextToDisplay is devided by rows, to determent the column amount
    const unsigned int columns = std::floor(ArrayOfTextToDisplay.size() / rows);
    
    for(int row = 0; row < rows; row++)
    {
        for(int level = 0; level < CellHeight; level++)
        {
            //Adds padding to the left side, usefull in displaying actions in center when displaying fight 
            Padding::PaddingLeft(PaddingLeftAmount);
            for(int column = 0; column < columns; column++)
            {
                std::cout << DisplayCell::display(level, SelectedColumn==column && SelectedRow==row, ArrayOfTextToDisplay[column+row], CellWidth, CellHeight);
            }
            std::cout << '\n';
        }
    }
}
