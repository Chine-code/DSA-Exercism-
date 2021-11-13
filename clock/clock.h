#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>
#include <sstream>

namespace date_independent
{
    class clock
    {
        public:
            clock(int, int);
            static clock at(int hour, int minute){return clock(hour, minute);}
            clock plus(int add){return clock(this->hour, this->minute + add);}
            operator std::string() const
            {
                std::string A = (this->hour < 10) ? "0" + std::to_string(this->hour)
                                            : std::to_string(this->hour);
                std::string B = ":";
                std::string C = 
                          (this->minute < 10) ? "0" + std::to_string(this->minute)
                                              : std::to_string(this->minute);
                return A + B + C;
            }
            bool operator==(const clock& other) const {return this->hour == other.hour
                                                        &&    this->minute == other.minute;}
            bool operator!=(const clock& other) const {return !(*this == other);}
        private:
            int hour{0},minute{0};
    };
}

#endif // CLOCK_H