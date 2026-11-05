#include <iostream>
#include "Custom_vector.h"

int main()
{
    CustomVector vec1(4);
    vec1.set(0, 958.4804);
    vec1.set(1, 61.665);
    vec1.set(2, 124.24);
    vec1.set(3, -54154.15);
    std::cout << "Vector 1 " << std::endl;
    for (int i = 0; i < vec1.get_size(); i++)
    {
        std::cout << vec1.get(i) << " ";
    }
    std::cout << std::endl;
    {
        CustomVector vec2(3);
        vec2[0] = 3.2568;
        vec2[1] = 84848.98;
        vec2[2] = 41.29;
        std::cout << "Vector 2 " << std::endl;
        for (int i = 0; i < vec2.get_size(); i++)
        {
            std::cout << vec2[i] << " ";
        }
        std::cout << std::endl;

        vec1 = vec2;
    }

    std::cout << "Vector 1 = Vector 2 " << std::endl;
    for (int i = 0; i < vec1.get_size(); i++)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
