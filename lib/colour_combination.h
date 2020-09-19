#ifndef COLOR_COMBINATION_H__
#define COLOR_COMBINATION_H__

#include <cassert>
#include <map>
#include <string>
#include <sstream>
#include <ostream>

#include "colour_code.h"
#include "escape_sequences.h"
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
		return START_ESCAPE "\e[0m" END_ESCAPE;
	}

	static std::string resetForegroundColour()
	{
		return START_ESCAPE "\e[39m" END_ESCAPE;
	}

	static std::string resetBackgroundColour()
	{
		return START_ESCAPE "\e[49m" END_ESCAPE;
	}

private:
	Colour	*foreground,
		*background;
};


std::ostream& operator<<( std::ostream& os, const ColourCombination& c );

#endif
