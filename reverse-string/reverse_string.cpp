#include "reverse_string.h"
#include <iostream>
#include <algorithm>

/* Mentor Comment
 std::string::length() returns an unsigned integer type. 
 If the argument is empty the expression input.length() - 1 gives you a large positive number. 
 But the assignment to int is implementation-defined if the int is not able to represent that value.
*/

namespace reverse_string
{
    std::string reverse_string(std::string input)
    {
        std::string result{};
        std::reverse(input.rbegin(), input.rend());
        return input;
    }
}  // namespace reverse_string
