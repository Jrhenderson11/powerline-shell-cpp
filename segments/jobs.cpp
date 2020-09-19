#include <unistd.h>
#include <pstreams/pstream.h>
#include <string>
#include <iostream>
#include <sys/param.h>

#include "colour_code.h"
#include "colour_combination.h"
#include "special_character.h"
#include "string_manipulation.h"

#include "jobs.h"


namespace jobs
{
	#include "themes/default.cpp"

	size_t stringCount(const std::string& str, const std::string& substr) {

		const size_t step = substr.size();

		size_t count(0);
		size_t pos(0);

		while((pos=str.find(substr, pos)) !=std::string::npos) {
			pos += step;
			++count;
		}

		return count;
	}

	std::string getSegment()
	{
		redi::ipstream proc("/bin/ps", redi::pstreams::pstdout | redi::pstreams::pstderr);
		std::string line;
		int num_jobs = 0;
		
		while (std::getline(proc.out(), line)) num_jobs++;	
		
		// Don't ask: 1 for columns desc, 1 for shell, one for ps ? 
		num_jobs -=6;
		
		if (num_jobs > 0) {
			ColourCombination &jobs = jobs_colours;
			return jobs.getColourCode() + std::to_string(num_jobs);
		} else {
			return "";
		}

	}
}

