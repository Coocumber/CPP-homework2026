#include <iostream>

#define PRINT(x) std::cout << (x) << std::endl

struct Sum
{
private:
    long long sum_;

public:
    Sum() : sum_(0) {};
    Sum(long long sum) : sum_(sum) {};

    void operator()(int n)
    {
        sum_ += n;
    }

    long long getSum()
    {
        return sum_;
    }

    void resetSum()
    {
        sum_ = 0;
    }
};

int main()
{
    Sum adder(0);
    PRINT(adder.getSum());
    adder(6);
    PRINT(adder.getSum());
    adder(23);
    adder(58);
    PRINT(adder.getSum());
    adder.resetSum();
    PRINT(adder.getSum());
}