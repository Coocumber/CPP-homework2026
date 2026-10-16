#include "shape.h"

const std::string &Shape::getName() const
{
    return name_;
}

double Shape::area()
{
    return 0.0;
}

double Shape::perimeter()
{
    return 0.0;
}

bool operator==(const Shape &lhs, const Shape &rhs)
{
    return abs(lhs.S_ - rhs.S_) < 1e-6;
}

bool operator^(const Shape &lhs, const Shape &rhs)
{
    return abs(lhs.P_ - rhs.P_) < 1e-6;
}