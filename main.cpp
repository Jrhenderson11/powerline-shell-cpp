#include <iostream>

#include "colour_code.h"
#include "colour_combination.h"
#include "special_character.h"

#include "currenttime.h"
#include "cwd.h"
#include "enumeratecolours.h"
#include "git.h"
#include "jobs.h"

int
main()
{
	#include "themes/default.cpp"


	std::cout << white_on_gray << cwd::getSegment();

	std::cout << white_on_gray << " " << git::getSegment();

	std::string jobs = jobs::getSegment();
	if (jobs != ""){
		std::cout << white_on_gray << " " << jobs;
	}

	std::cout << white_on_gray << " " << "\\$";

	std::cout << ColourCombination( &darkgray, NULL ) << special("separator") << " ";


	std::cout << ColourCombination::resetColour();

	return 0;
}
