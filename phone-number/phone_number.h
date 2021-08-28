#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <string>

namespace phone_number
{
    struct phone_number
    {
        auto number() const -> std::string;
        std::string number FUNCTION_name();
        auto area_code() const -> std::string;
        phone_number(std::string&& number);
        operator std::string() const
        {
            return this->no_with_area_code;
        }
    private:
        std::string no{};// Plain Phone Number 
        std::string area_code_number{};// Area Code Number
        std::string no_with_area_code{};// Algorthimic Combination of Phone Number and Area Code Number
        bool is_area_code_available{false};
    };
    
}  // namespace phone_number

#endif // PHONE_NUMBER_H