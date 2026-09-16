#include <random>
#include <iostream>

int main()
{
    std::random_device rd;                        // non-deterministic generator
    std::mt19937 gen(rd());                       // to seed mersenne twister.
    std::uniform_int_distribution<> dist(1, 100); // distribute results between 1 and 6 inclusive.
    short int n = dist(gen);
    short int k = -1;
    std::cout << "Угадай число N от 1 до 100" << std::endl;
    std::cout << "Число загаданно, ожидается первая попытка ввода:" << std::endl;
    std::cin >> k;

    while (k != n)
    {
        if (k > n)
        {
            std::cout << "N << " << k << std::endl;
        }
        else
        {
            std::cout << "N >> " << k << std::endl;
        }
        std::cin >> k;
    }
    std::cout << "Число найдено. N = " << n << std::endl;
}