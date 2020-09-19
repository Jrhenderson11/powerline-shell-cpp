#include <ostream>

#include "colour_code.h"
#include "colour_combination.h"
#include "special_character.h"

//http://zsh.sourceforge.net/Doc/Release/Prompt-Expansion.html
std::string ColourCombination::getColourCode() const
{
	std::stringstream code;
	if( foreground )
		code << START_ESCAPE << "\e" << "[38;5;" << foreground->value() << "m" << END_ESCAPE;
	else
		code << resetForegroundColour();
		
	if( background )
		code << START_ESCAPE << "\e" << "[48;5;" << background->value() << "m" << END_ESCAPE;
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
