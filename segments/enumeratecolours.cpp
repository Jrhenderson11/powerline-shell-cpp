#include <sstream>

#include "colour_code.h"
#include "colour_combination.h"

#include "enumeratecolours.h"


namespace enumeratecolours
{
	static std::string EnumerateColours();
	static std::string EnumerateGrayscale();


	std::string getSegment()
	{
		std::stringstream segmentString;

		segmentString << ColourCombination::resetColour();
		segmentString << EnumerateColours()    << std::endl;
		segmentString << EnumerateGrayscale() << std::endl;

		return segmentString.str();
	}


	static std::string EnumerateColours()
	{
		std::stringstream rainbow;

		// legend for green boxes
		for( unsigned short g = 0; g < 6; ++g )
			rainbow << "          green = " << g << "        ";
		rainbow << std::endl << std::endl;

		// legend for blue values
		rainbow << "   blue = ";
		for( unsigned short g = 0; g < 6; ++g )
		{
			for( unsigned short b = 0; b < 6; ++b )
				rainbow << " " << b << "  ";
			rainbow << "   ";
		}
		rainbow << std::endl << std::endl;
		
		for( unsigned short r = 0; r < 6; ++r )
		{
			rainbow << " red = " << r << "  ";
			for( unsigned short g = 0; g < 6; ++g )
			{
				for( unsigned short b = 0; b < 6; ++b )
				{
					Colour256 fg = Colour256(r,g,b),
						 bg = Colour256(r,g,b);
					rainbow << ColourCombination( &fg, &bg ) << "  ";
					rainbow << ColourCombination::resetColour() << "  ";
				}
				rainbow << "   ";
			}
			rainbow << ColourCombination::resetColour() << std::endl << std::endl;
		}

		return rainbow.str();
	}


	static std::string EnumerateGrayscale()
	{
		std::stringstream rainbow;
		for( unsigned short g = 0; g < 24; ++g )
		{
			rainbow.width( 2 );
			rainbow << std::right << g;
			rainbow << "  ";
		}
		rainbow << std::endl;

		for( unsigned short g = 0; g < 24; ++g )
		{
			GrayScale gray = GrayScale( g );
			rainbow << ColourCombination( &gray, &gray ) << "  ";
			rainbow << ColourCombination::resetColour() << "  ";
		}

		rainbow << ColourCombination::resetColour() << std::endl << std::endl;
		
		return rainbow.str();
	}
}
