#include <unistd.h>
#include <sys/param.h>

#include "colour_code.h"
#include "colour_combination.h"
#include "special_character.h"
#include "string_manipulation.h"


#include "cwd.h"

namespace cwd
{
	#include "themes/default.cpp"

	ColourCombination &separatorColours = short_cwd_separator;
	ColourCombination &textColours = short_cwd;
	ColourCombination &defaultColours = white_on_gray;


	std::string shortenPath(std::string path, std::string long_part, std::string short_part, int end)
	{
		if (end == 0) {
			return replaceAllSubstrings( path, long_part, ( textColours.getColourCode() + " " + short_part + separatorColours.getColourCode() + special("separator") + defaultColours.getColourCode() + " ") );
		} else {
			return replaceAllSubstrings( path, long_part, ( textColours.getColourCode() + " " + short_part + separatorColours.getColourCode() + special("separator") + defaultColours.getColourCode()) );
		}
		
	}

	std::string getSegment()
	{
		char cpath[MAXPATHLEN];
		if( getcwd(cpath, sizeof(cpath)/sizeof(char)) == NULL ){
			return "";
		}

		std::string path = cpath;

		// Originally done with a map, but doing with series of ifs allows more flexibility in ordering and mutually exclusive options
		if (path.find("/home/james/Documents/CTF", 0) != std::string::npos) {

			path = shortenPath(path, "/home/james/Documents/CTF/", "CTF ", 0);
			path = shortenPath(path, "/home/james/Documents/CTF", "CTF ", 1);

		} else if (path.find("/home/james/Documents/git", 0) != std::string::npos) {

			path = shortenPath(path, "/home/james/Documents/git/", "git ", 0);
			path = shortenPath(path, "/home/james/Documents/git", "git ", 1);

		} else if (path.find("/home/james", 0) != std::string::npos) {

			path = shortenPath(path, "/home/james/", "~ ", 0);
			path = shortenPath(path, "/home/james", "~ ", 1);

		}

		if( (path.length() > 1) && (path[0] == '/') ){
			path = path.substr( 1 );
		}

		path = replaceAllSubstrings( path, "/", " " + special("separator_thin") + " " );

		return path;
	}
}

