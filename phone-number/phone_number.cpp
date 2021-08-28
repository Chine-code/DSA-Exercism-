#include "phone_number.h"
#include <iostream>
#include <string>
#include <cctype>
#include <exception>
#include <algorithm>
namespace phone_number
{
    phone_number::phone_number(std::string &&number)
    {
        // Get Phone Number
        for (char word : number)
        {   
            // Check If ASCII Characters is between 32 && 47,then check If it's 1 and Ignore them all
            if ( ((int)word >= 32 && (int)word < 47))    continue;
            no += word;
        }
        // Remove 1 From First Number IF it is the First digit
        std::string temp = no;
        if (no[0] == '1')   no.clear(),no = &temp[1];

        // Get Area code Number If It is Seperated by Brackets or Dots
        for (char word : number)
        {
            // Identifies an Area Code Number Because of It's Brackets or It's dots
            if (word == '(' || word == '.')    this->is_area_code_available = true;
            if (is_area_code_available) this->area_code_number += word;
            if (word == ')' || word == '.')    this->is_area_code_available = false;
        }

        // Get Area Code Number If Phone Number has Lots of Unneccesary Spaces
        if (std::count(number.begin(), number.end(), ' ') > 2)
        {   // Removes Unnecessary Space From Phone Numbers
            for (unsigned index = 0; index < number.size(); index++)
                if (number[index] == ' ')
                    {   // break Loop and Collect all numbers before the First Occuring Space
                        this->area_code_number = number.substr(0, index);
                        break;
                    }
        }

        // Get Area Code Number If Phone Number Has Decimals
        if (this->area_code_number.front() == '.')
        {
            std::string temp = number;
            this->area_code_number.clear();
            this->area_code_number = number.substr(0, 3);
        }
        // Inserts Brackets Before and After the area code number If not available
        {   // Not all Phone Numbers have Brackets in their Input
            if (this->area_code_number.front() != '(')  this->area_code_number.insert(0, "(");
            if (this->area_code_number.back()  != ')')  this->area_code_number += ")";
        }

        // Algorithm for mixing Area Code Number with Phone Number
        this->no_with_area_code += area_code_number;
        this->no_with_area_code += ' ';// Create Space after Identifying Area Code Number
        // Then, mix the Number with the remaining Numbers
        this->no_with_area_code += this->no.substr(area_code_number.size() - 2);
        // Insert a hyphen before 4 Numbers to  the End.
        this->no_with_area_code.insert(no_with_area_code.size() - 4,"-");

        // InVAlid CAses
        {
            if (no[0] != '1' && no.size() == 11)
                throw std::domain_error("invalid_when_11_digits_does_not_start_with_a_1");

            if (no.size() != 10)
                throw std::domain_error("invalid_when_not_10_exact_digits");
            
            if (no.front() == '0')
                throw std::domain_error("invalid_if_exchange_code_starts_with_0");

            if (this->area_code()[0] == '1')
                throw std::domain_error("invalid_if_area_code_starts_with_1_on_valid_11_digit_number");

            int area_code_size = this->area_code().size();
            std::string digits_after_area_code = no.substr(area_code_size, no.size() - 1);
            if (digits_after_area_code[0] == '0' || digits_after_area_code[0] == '1')
                throw std::domain_error
                ("invalid_if_exchange_code_starts_with_0_on_valid_11_digit_number or "
                 "invalid_if_exchange_code_starts_with_0 or invalid_if_exchange_code_starts_with_1");
        }

    }

    auto phone_number::number() const -> std::string
    {
        return this->no;
    }

    auto phone_number::area_code() const -> std::string
    {
        // Remove Brackets at Both Ends
        return this->area_code_number.substr(1, area_code_number.size() - 2);
    }
}  // namespace phone_number
