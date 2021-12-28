#if !defined(SAY_H)
#define SAY_H

#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace say
{
    struct NumberToWord
    {
        unsigned int number;
        std::string words;
    };


    std::string getWordRepresentationOfNumber(NumberToWord &);

    std::string in_english(unsigned long long&&);

} // namespace say

#endif // SAY_H