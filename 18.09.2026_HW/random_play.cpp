#include <random>
#include <iostream>

void play()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);
    short int n = dist(gen);
    short int k = -1;
    std::cout << "Угадай число N от 1 до 100" << std::endl;
    std::cout << "Число загаданно, ожидается первая попытка ввода:" << std::endl;
    std::cin >> k;

    while (k != n)
    {
        if (k > n)
        {
            std::cout << "N << " << k << " (Less)" << std::endl;
        }
        else
        {
            std::cout << "N >> " << k << " (Greater)" << std::endl;
        }
        std::cin >> k;
    }
    std::cout << "Число найдено. N = " << n << std::endl;
}

int main()
{
    while (true)
    {
        play();
    }
}
