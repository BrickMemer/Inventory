#include "Displaycell.hpp"
#include <string>
#include <cmath>

std::string DisplayCell::display(const int& level, const bool& isSelected, const std::string& TextInside, const int& CellWidth, const int& CellHeight)
{
    std::string NameToDisplay = "";
    short MiddleSpot = 0;
    std::string TextToDisplay = TextInside;
    
    if(TextInside.size() > CellWidth)
    {
        TextToDisplay.resize(CellWidth);
    }

    if(level == 0 || level == CellHeight - 1)
    {
        //Start of line
        NameToDisplay.append(" +");


        for (int i = 0; i < CellWidth; ++i) {
            NameToDisplay.append("-");
        }

        //End of line
        NameToDisplay.append("+ ");
    }
    else if(level == std::floor((CellHeight-1)/2.f))
    {
        //Start of line
        if(isSelected){
            NameToDisplay.append(">|");
        }else {
            NameToDisplay.append(" |");
        }

        MiddleSpot = std::floor((CellWidth - TextToDisplay.length()) / 2.f);
        for(size_t z = 0; z < MiddleSpot; z++)
        {
            NameToDisplay.append(" ");
        }
        NameToDisplay.append(TextToDisplay);
        int SpaceLeft = CellWidth - NameToDisplay.length() + 2;
        for(size_t z = 0; z < SpaceLeft; z++)
        {
            NameToDisplay.append(" ");
        }
        //End of line
        if(isSelected){
            NameToDisplay.append("|<");
        }else {
            NameToDisplay.append("| ");
        }
    }
    else
    {
        //Start of line
        if(isSelected){
            NameToDisplay.append(">|");
        }else {
            NameToDisplay.append(" |");
        }


        for (int i = 0; i < CellWidth; ++i) {
            NameToDisplay.append(" ");
        }

        //End of line
        if(isSelected){
            NameToDisplay.append("|<");
        }else {
            NameToDisplay.append("| ");
        }
    }
    return NameToDisplay;
}

