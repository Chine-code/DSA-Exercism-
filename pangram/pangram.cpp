#include "pangram.h"

#include <cctype>
#include <algorithm>

// 1. Convert all the words to either all lower or all upper characters.
// 2. Create an Array of Size 26(No of English Alphabets).
// 3. Loop through each character in the given string and 
//    assign a value in the array based on the character ASCII Value(Must be betweeen 97 & 122 Inclusive)
// 4. Check if any index is Zero After Looping(this indicates not a pangram)


namespace pangram
{
    bool is_pangram(std::string&& word)
    {
        // Change the Words to either all lower cases or all upper cases.
        std::transform(word.begin(), word.end(), word.begin(), [&](char a)
        {
            return std::tolower(a);
        });

        // Make Sure all Values in the Array has a Value of Zero.
        int alphabets[26] = {};

        for (std::string::iterator it = word.begin(); it != word.end(); it++)
        {
            // If Current Character is not an alphabet,Skip over to next character
            if ( int(*it) < 97 && (int)*it > 122 )    continue;
            alphabets[ int(*it) - 97 ]++;
        }

        for (int alphabet : alphabets)
            if (alphabet == 0)
                return false;

        return true;
    }
}  // namespace pangram
