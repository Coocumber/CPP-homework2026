#include "shape.h"

Square::Square(std::string name, double lengh)
    : Rectangular(name, lengh, lengh)
{
}

Square::Square(const Square &other)
    : Rectangular(other)
{
}

Square::Square(Square &&other)
    : Rectangular(other)
{
}

Square &Square::operator=(const Square &other)
{
    weight_ = other.weight_;
    hight_ = other.hight_;
    S_ = other.S_;
    P_ = other.P_;
    return *this;
}

Square &Square::operator=(Square &&other)
{
    weight_ = other.weight_;
    hight_ = other.hight_;
    S_ = other.S_;
    P_ = other.P_;

    other.weight_ = 0;
    other.hight_ = 0;
    other.S_ = 0;
    other.P_ = 0;

    return *this;
}

bool operator==(const Square &lhs, const Square &rhs)
{
    return abs(lhs.S_ - rhs.S_) < 1e-6;
}

bool operator^(const Square &lhs, const Square &rhs)
{
    return abs(lhs.P_ - rhs.P_) < 1e-6;
}

std::ostream &operator<<(std::ostream &stream, const Square &rhs)
{
    stream << "Figure: " << rhs.name_ << " | ";
    stream << "Figure_size " << rhs.weight_ << " | ";
    stream << "Area: " << rhs.S_ << " | ";
    stream << "Perimeter: " << rhs.P_;
    return stream;
}
