#include "Displaycell.hpp"

std::string DisplayCell::display(int level, bool isSelected, const std::string& TextInside)
{
    std::string NameToDisplay;
    unsigned short SpaceBetween = 24;
    short MiddleSpot;

    switch (level) {
    case 0:
        //Start of line
        NameToDisplay.append(" +");


        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append("-");
        }

        //End of line
        NameToDisplay.append("+ ");
        break;
    case 1:
    case 3:
    case 4:
        //Start of line
        if(isSelected){
            NameToDisplay.append(">|");
        }else {
            NameToDisplay.append(" |");
        }


        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append(" ");
        }

        //End of line
        if(isSelected){
            NameToDisplay.append("|<");
        }else {
            NameToDisplay.append("| ");
        }
        break;
    case 2:
        //Start of line
        if(isSelected){
            NameToDisplay.append(">|");
        }else {
            NameToDisplay.append(" |");
        }

        MiddleSpot = static_cast<short>((SpaceBetween - TextInside.length()) / 2);
        for(size_t z = 0; z < MiddleSpot; z++)
        {
            NameToDisplay.append(" ");
        }
        NameToDisplay.append(TextInside);
        for(size_t z = 0; z < MiddleSpot; z++)
        {
            NameToDisplay.append(" ");
        }
        if(TextInside.length() % 2 != 0)
        {
            NameToDisplay.append(" ");
        }

        //End of line
        if(isSelected){
            NameToDisplay.append("|<");
        }else {
            NameToDisplay.append("| ");
        }
        break;
    case 5:
        //Start of line
        NameToDisplay.append(" +");

        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append("-");
        }

        //End of line
        NameToDisplay.append("+ ");
        break;
    default:
        for (int i = 0; i < SpaceBetween; ++i) {
            NameToDisplay.append(" ");
        }
        break;
    }
    return NameToDisplay;
}

