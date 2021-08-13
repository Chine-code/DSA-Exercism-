#include "reverse_string.h"
#include <iostream>
#include <algorithm>
namespace reverse_string
{
    std::string reverse_string(std::string input)
    {
        // std::string result{};
        // for (int i = input.length() - 1; i != -1; i--)   result += input[i];

        std::reverse(input.rbegin(), input.rend());
        return input;
    }
}  // namespace reverse_string
