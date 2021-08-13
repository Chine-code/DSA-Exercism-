#include "leap.h"

namespace leap
{
    bool is_leap_year(unsigned year)
    {
        if (year % 4) return false;// Obviously not a Leap Year.
        if (year % 4 == 0)//Likely a Leap Year
            if (year % 100 == 0 && year % 400 != 0) return false;//Not Leap if The Century is not divisible by 400
        return true;
    }
}  // namespace leap
