#include "Displaycell.hpp"
#include <string>
#include <cmath>

std::string DisplayCell::display(const int& level, const bool& isSelected, const std::string& TextInside, const int& CellWidth, const int& CellHeight)
{
    /*
        Configuration
    */
    
    std::string NameToDisplay = "";
    short MiddleSpot = 0;
    std::string TextToDisplay = TextInside;

    //Cut Text if size of it is smaller then cell width
    if(TextInside.size() > CellWidth)
    {
        TextToDisplay.resize(CellWidth);
    }

    //on beginning or end of cell height it draws a different ending
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
    //if level is in between CellHeight, draw text inside the cell
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
    // if none of above are true, draw a in between frame
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
