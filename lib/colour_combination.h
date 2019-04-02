#ifndef COLOR_COMBINATION_H__
#define COLOR_COMBINATION_H__

#include <cassert>
#include <map>
#include <string>
#include <sstream>
#include <ostream>

#include "colour_code.h"
#include "special_character.h"


class ColourCombination
{
public:
	ColourCombination( Colour* const fg, Colour* const bg )
		: foreground(fg)
		, background(bg)
	{}

	void inverse();

	std::string getColourCode() const;

	Colour* getForegroundColour();
	Colour* getBackgroundColour();

	static std::string resetColour()
	{
		return "\\[\\e[0m\\]";
	}

	static std::string resetForegroundColour()
	{
		return "\\[\\e[39m\\]";
	}

	static std::string resetBackgroundColour()
	{
		return "\\[\\e[49m\\]";
	}

private:
	Colour	*foreground,
		*background;
};


std::ostream& operator<<( std::ostream& os, const ColourCombination& c );

#endif
