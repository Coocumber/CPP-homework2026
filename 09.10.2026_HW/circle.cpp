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
    name_ = other.name_;
    R_ = other.R_;
    S_ = other.S_;
    P_ = other.P_;
}

Circle::Circle(Circle &&other)
{
    name_ = other.name_;
    R_ = other.R_;
    S_ = other.S_;
    P_ = other.P_;

    other.name_ = "";
    other.R_ = 0;
    other.S_ = 0;
    other.P_ = 0;
}

Circle &Circle::operator=(const Circle &other)
{
    name_ = other.name_;
    R_ = other.R_;
    S_ = other.S_;
    P_ = other.P_;
    return *this;
}

Circle &Circle::operator=(Circle &&other)
{
    name_ = other.name_;
    R_ = other.R_;
    S_ = other.S_;
    P_ = other.P_;

    other.name_ = "";
    other.R_ = 0;
    other.S_ = 0;
    other.P_ = 0;

    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Circle &rhs)
{
    stream << "Figure: " << rhs.name_ << " | ";
    stream << "Figure_size " << rhs.R_ << " | ";
    stream << "Area: " << rhs.S_ << " | ";
    stream << "Perimeter: " << rhs.P_;
    return stream;
}
