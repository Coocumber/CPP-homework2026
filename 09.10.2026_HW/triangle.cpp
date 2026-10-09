#include "shape.h"

Triangle::Triangle(std::string name, double a, double b, double c)
    : a_(a), b_(b), c_(c), p_((a + b + c) / 2)
{
    if (p_ < 0 || a >= c + b || b >= c + a || c >= a + b)
    {
        throw std::range_error("not a tringle");
    }
    name_ = name;
    S_ = std::pow((p_ * (p_ - a_) * (p_ - b_) * (p_ - c_)), 0.5);
    P_ = a_ + b_ + c_;
}

double Triangle::area()
{
    return S_;
}

double Triangle::perimeter()
{
    return P_;
}

Triangle::Triangle(const Triangle &other)
{
    a_ = other.a_;
    b_ = other.b_;
    c_ = other.c_;
    S_ = other.S_;
    P_ = other.P_;
    p_ = other.p_;
}

Triangle::Triangle(Triangle &&other)
{
    a_ = other.a_;
    b_ = other.b_;
    c_ = other.c_;
    S_ = other.S_;
    P_ = other.P_;
    p_ = other.p_;

    other.a_ = 0;
    other.b_ = 0;
    other.c_ = 0;
    other.S_ = 0;
    other.P_ = 0;
    other.p_ = 0;
}

Triangle &Triangle::operator=(const Triangle &other)
{
    a_ = other.a_;
    b_ = other.b_;
    c_ = other.c_;
    S_ = other.S_;
    P_ = other.P_;
    p_ = other.p_;
    return *this;
}

Triangle &Triangle::operator=(Triangle &&other)
{
    a_ = other.a_;
    b_ = other.b_;
    c_ = other.c_;
    S_ = other.S_;
    P_ = other.P_;
    p_ = other.p_;

    other.a_ = 0;
    other.b_ = 0;
    other.c_ = 0;
    other.S_ = 0;
    other.P_ = 0;
    other.p_ = 0;
    return *this;
}

bool operator==(const Triangle &lhs, const Triangle &rhs)
{
    return abs(lhs.S_ - rhs.S_) < 1e-6;
}

bool operator^(const Triangle &lhs, const Triangle &rhs)
{
    return abs(lhs.P_ - rhs.P_) < 1e-6;
}

std::ostream &operator<<(std::ostream &stream, const Triangle &rhs)
{
    stream << "Figure: " << rhs.name_ << " | ";
    stream << "Figure_size " << rhs.a_ << ", " << rhs.b_ << ", " << rhs.c_ << " | ";
    stream << "Area: " << rhs.S_ << " | ";
    stream << "Perimeter: " << rhs.P_;
    return stream;
}
