#include "isogram.h"

#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
namespace isogram
{
	bool is_isogram( std::string &&word)
	{
		// Transform all letters to All Caps Or All Small Letters
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		if (word.empty())	return true;// returns true if empty

		for (unsigned int i = 0; i < word.length(); i++)
		{
			//Only These Special Characters can be repeated
			if (word[i] != ' ' && word[i] != '_' && word[i] != '-')
				// Check if each words repeats more than once,If it does,It is not an Isogram
				if( std::count(word.begin(), word.end(), word[i]) > 1 )
					return false;
		}
		// No word was Repeated,So return true
		return true;
	}
}  // namespace isogram
