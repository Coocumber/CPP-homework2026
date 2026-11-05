#include <iostream>
#include "Custom_vector.h"

int main()
{
    CustomVector vec(4);
    vec.set(0, 958.4804);
    vec.set(1, 61.665);
    vec.set(2, 124.24);
    vec.set(3, -54154.15);
    std::cout << "Vector" << std::endl;
    for (int i = 0; i < vec.get_size(); i++)
    {
        std::cout << vec.get(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}