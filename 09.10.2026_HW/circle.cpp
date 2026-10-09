#include "shape.h"

Circle::Circle(std::string name, double R)
    : R_(R)
{
    if (R_ <= 0)
    {
        throw std::range_error("not a Circle");
    }
    name_ = name;
    S_ = M_PI * R_ * R_;
    P_ = 2 * M_PI * R_;
}

double Circle::area()
{
    return S_;
}

double Circle::perimeter()
{
    return P_;
}

Circle::Circle(const Circle &other)
{
    R_ = other.R_;
    S_ = other.S_;
    P_ = other.P_;
}

Circle::Circle(Circle &&other)
{
    R_ = other.R_;
    S_ = other.S_;
    P_ = other.P_;

    other.R_ = 0;
    other.S_ = 0;
    other.P_ = 0;
}

Circle &Circle::operator=(const Circle &other)
{
    R_ = other.R_;
    S_ = other.S_;
    P_ = other.P_;
    return *this;
}

Circle &Circle::operator=(Circle &&other)
{
    R_ = other.R_;
    S_ = other.S_;
    P_ = other.P_;

    other.R_ = 0;
    other.S_ = 0;
    other.P_ = 0;

    return *this;
}

bool operator==(const Circle &lhs, const Circle &rhs)
{
    return abs(lhs.S_ - rhs.S_) < 1e-6;
}

bool operator^(const Circle &lhs, const Circle &rhs)
{
    return abs(lhs.P_ - rhs.P_) < 1e-6;
}

std::ostream &operator<<(std::ostream &stream, const Circle &rhs)
{
    stream << "Figure: " << rhs.name_ << " | ";
    stream << "Figure_size " << rhs.R_ << " | ";
    stream << "Area: " << rhs.S_ << " | ";
    stream << "Perimeter: " << rhs.P_;
    return stream;
}
