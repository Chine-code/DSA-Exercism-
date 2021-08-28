#include "binary_search.h"

#include <cmath>
#include <iostream>
namespace binary_search
{
    std::size_t find(const std::vector<int> &data, const int &search_element)
    {
        // Assumes The Data is Alredy Sorted
        std::size_t size_of_data = data.size();
        int mid = size_of_data / 2, start_point = 0, end_point = size_of_data;
        for (unsigned i{0}; i < data.size(); i++)
        {
            if (data[mid] == search_element)   return mid;
            else if (data[mid] >= search_element)
            {
                end_point = mid;
                mid = (start_point + mid) / 2;
            }
            else if (data[mid] <= search_element)
            {
                start_point = mid;
                mid = (mid + end_point) / 2; 
            }
            // else if (start_point == mid)    throw std::domain_error("Mid Point == Start Point\n");
        }
        throw std::domain_error("Throws Because Does not Fufill Conditions");
        return -1;
    }
} // namespace binary_search
