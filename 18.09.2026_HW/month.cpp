#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void month_converter(int n)
{
    // std::cin >> n;
    if (n >= 1 && n <= 12)
    {
        std::cout << month[n - 1] << std::endl;
    }
    else
    {
        std::cout << "Fail number" << std::endl;
    }
}

int main()
{
    // Test
    for (int i = -10; i <= 20; i++)
    {
        std::cout << i << " ";
        month_converter(i);
    }
}