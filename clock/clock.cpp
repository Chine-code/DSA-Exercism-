#include "clock.h"

#include <iostream>
namespace date_independent 
{
    clock::clock(int hour, int minute)
    {
        // Convert hour to a 24 hour format
        if (hour > 0)   this->hour = hour % 24;
        // Convert Minute to a 60 minute format and add possible extra hours from minutes to hour
        if (minute > 0)
        {
            this->hour += static_cast<int>(minute / 60);
            this->hour %= 24;
            this->minute += minute % 60;
        }

        // Convert negative hour to positive hour
        if (hour < 0)
        {
            int smallest_negative_hour = static_cast<int>(std::abs(hour) / 24);
            this->hour = hour + 24 * (smallest_negative_hour + 1);// Turns negative hour to positive hour
        }
        
        // Convert negative minute to positive minute
        int subtract_value{0};
        if (minute < 0)
        {
            int smallest_negative_minute = static_cast<int>(std::abs(minute) / 60);
            subtract_value = (smallest_negative_minute + 1);
            this->minute = minute + 60 * subtract_value;// Turns negative minute to positive minute
        }

        subtract_value %= 24;
        // if hour is less than 12 and we had negative minutes as input,
        // we modify hours
        if (this->hour < 12 && minute < 0)    
        {
            this->hour += (24 - (subtract_value) );
            this->hour %= 24;
        }
        else if (this->hour >= 12 && minute < 0) this->hour -= subtract_value;

    }
}  // namespace date_independent
