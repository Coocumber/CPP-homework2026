#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main()
{
    int n = 0;
    std::cin >> n;
    std::cout << month[n - 1] << std::endl;
    return 0;
}