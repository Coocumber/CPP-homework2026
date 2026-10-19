#include <iostream>
#include <algorithm>
#include <vector>
#include "student.h"

int main()
{
    std::vector<Student> MIPT_class = {{"Ivan", "BAS", {4, 6, 4, 7, 8, 3, 5, 6}},
                                       {"Vovan", "AT", {4, 6, 7, 8, 4, 6, 7, 8}},
                                       {"Igor", "PI", {5, 8, 3, 9, 6, 8, 9, 4}}};

    for (const Student &pers : MIPT_class)
    {
        std::cout << pers << std::endl;
    }

    std::cout << (MIPT_class[2] > MIPT_class[1]) << (MIPT_class[2] < MIPT_class[1]) << std::endl;

    std::sort(MIPT_class.begin(), MIPT_class.end(), [](const Student &lhs, const Student &rhs)
              { return lhs.getAverageScore() < rhs.getAverageScore(); });

    for (const Student &pers : MIPT_class)
    {
        std::cout << pers << std::endl;
    }

    return 0;
}