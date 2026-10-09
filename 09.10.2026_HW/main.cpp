#include <iostream>
#include "shape.h"

int main()
{
    Triangle tring("Tring_1", 3, 4, 5);
    std::cout << tring << std::endl;

    Rectangular rect("Rect_2", 23, 6.58);
    std::cout << rect << std::endl;

    Circle circ("Circ_3", 14.95);
    std::cout << circ << std::endl;

    Square square("Square_4", 36.6);
    std::cout << square << std::endl;

    return 0;
}