#include <iostream>
#include <string>
#include "Custom_vector.h"
#include <algorithm>

int main()
{
    CustomVector<std::string> vec1({"ccc", "ddd", "aaa", "eee"});
    std::cout << "Vector 1: ";
    for (int i = 0; i < vec1.size(); i++)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector 1: ";
    std::sort(vec1.begin(), vec1.end());
    for (int i = 0; i < vec1.size(); i++)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    // ----------------------------------------------------
    CustomVector<int> vec2({6, 7, 8, 3, 4, 2, 1});

    std::cout << "Vector 2: ";
    for (int i = 0; i < vec2.size(); i++)
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector 2: ";
    std::sort(vec2.begin(), vec2.end(), [](const int &lhs, const int &rhs)
              { return lhs > rhs; });
    for (int i = 0; i < vec2.size(); i++)
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
