#include <ostream>

#include "colour_code.h"
#include "colour_combination.h"
#include "special_character.h"

std::string ColourCombination::getColourCode() const
{
	std::stringstream code;
	if( foreground )
		code << special( "esc" ) << "[38;5;" << foreground->value() << "m";
	else
		code << resetForegroundColour();
		
	if( background )
		code << special( "esc" ) << "[48;5;" << background->value() << "m";
	else
		code << resetBackgroundColour();

	return code.str();
}


void ColourCombination::inverse()
{
	Colour *tmp	= foreground;
	foreground	= background;
	background	= tmp;
}


Colour* ColourCombination::getForegroundColour()
{
	return foreground;
}

Colour* ColourCombination::getBackgroundColour()
{
	return background;
}


std::ostream& operator<<( std::ostream& os, const ColourCombination& c )
{
	os << c.getColourCode();
	return os;
}
