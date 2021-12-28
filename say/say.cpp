#include "say.h"

#include <iostream>
#include <unordered_map>
#include <utility>

namespace say
{
    NumberToWord numberToWords[] =
        {{0, "zero"},
         {1, "one"},
         {2, "two"},
         {3, "three"},
         {4, "four"},
         {5, "five"},
         {6, "six"},
         {7, "seven"},
         {8, "eight"},
         {9, "nine"},
         {10, "ten"},
         {11, "eleven"},
         {12, "twelve"},
         {13, "thirteen"},
         {14, "fourteen"},
         {15, "fifteen"},
         {16, "sixteen"},
         {17, "seventeen"},
         {18, "eighteen"},
         {19, "nineteen"},
         {20, "twenty"},
         {30, "thirty"},
         {40, "forty"},
         {50, "fifty"},
         {60, "sixty"},
         {70, "seventy"},
         {80, "eighty"},
         {90, "ninety"},
         {100, "hundred"},
         {1000, "thousand"},
         {1000000, "million"},
         {1000000000, "billion"}};
    std::unordered_map<unsigned int, std::string> ntw;//numbertoWords

    void put_in_pairs()
    {
        for (const auto i : numberToWords)
        {
            ntw[i.number] = i.words;
        }
    }

    std::string getWordRepresentationOfNumber(unsigned long long &number)
    {

        if (number < 100)
        {
            int tens_digit = number / 10;
            int unit_digit = number % 10;

            if (number < 21)
            {
                return ntw[number];
            }
            else // 21 - 99
            {
                int tens = tens_digit * 10;
                return ntw[tens] + "-" + ntw[unit_digit];
            }
        }
        else if (number > 99 && number < 1000) // 100 - 999
        {
            int hundredth_digit = number / 100;
            unsigned long long other_digits = number % 100;
            bool isHundred = (other_digits == 0) ? true : false; // True If 100,200,300,400 e.t.c
            std::string words_of_other_digits = getWordRepresentationOfNumber(other_digits);


            if (isHundred)
            {
                return ntw[number / 100] + " hundred";
            }
            else
            {
                return ntw[hundredth_digit] + " hundred " + words_of_other_digits;
            }
        }
        else if (number > 999 && number < 1000000) // 1000 - 999,999
        {
            unsigned long long thousands_digit = number / 1000;
            unsigned long long other_digits = number % 1000;
            bool isThousand = (other_digits == 0) ? true : false; // True If (1000),(20,000),(300,000),(4,000) e.t.c

            std::string words_in_thousand = getWordRepresentationOfNumber(thousands_digit);
            std::string words_of_remaining = getWordRepresentationOfNumber(other_digits);

            if (isThousand)
            {
                return words_in_thousand + " thousand";
            }
            else
            {
                return words_in_thousand + " thousand " + words_of_remaining;
            }
            
        }
        else if (number > 999999 && number < 1000000000)// 1,000,000 - 999,999,999
        {
            unsigned long long million_digit = number / 1000000;
            unsigned long long other_digits = number % 1000000;
            /*
             True If (1,000,000),(20,000,000),(300,000,000),(4,000,000) e.t.c
            */
            bool isMillion = (other_digits == 0) ? true : false; 

            std::string words_in_million= getWordRepresentationOfNumber(million_digit);
            std::string words_of_remaining = getWordRepresentationOfNumber(other_digits);

            if (isMillion)
            {
                return words_in_million + " million";
            }
            else
            {
                return words_in_million + " million " + words_of_remaining;
            }
        }
        else if (number > 999999999 && number < 1000000000000)// 1,000,000,000 - 999,999,999,999
        {
            unsigned long long billion_digit = number / 1000000000;
            unsigned long long other_digits  = number % 1000000000;
            /*
             True If (1,000,000,000),(20,000,000,000),(300,000,000,000),(4,000,000,000) e.t.c
            */
            bool isBillion = (other_digits == 0) ? true : false; 

            std::string words_in_billion= getWordRepresentationOfNumber(billion_digit);
            std::string words_of_remaining = getWordRepresentationOfNumber(other_digits);

            if (isBillion)
            {
                return words_in_billion + " billion";
            }
            else
            {
                return words_in_billion + " billion " + words_of_remaining;
            }

        }
        else
        {
            throw std::domain_error("Error");
        }
        return "null";
    }

    std::string in_english(unsigned long long &&number)
    {
        put_in_pairs();
        if (number == 0)            return ntw[number];

       return getWordRepresentationOfNumber(number);
    }

} // namespace say
