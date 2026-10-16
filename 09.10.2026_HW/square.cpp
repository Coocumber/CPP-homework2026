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
    name_ = other.name_;
    weight_ = other.weight_;
    hight_ = other.hight_;
    S_ = other.S_;
    P_ = other.P_;
    return *this;
}

Square &Square::operator=(Square &&other)
{
    name_ = other.name_;
    weight_ = other.weight_;
    hight_ = other.hight_;
    S_ = other.S_;
    P_ = other.P_;

    other.name_ = "";
    other.weight_ = 0;
    other.hight_ = 0;
    other.S_ = 0;
    other.P_ = 0;

    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Square &rhs)
{
    stream << "Figure: " << rhs.name_ << " | ";
    stream << "Figure_size " << rhs.weight_ << " | ";
    stream << "Area: " << rhs.S_ << " | ";
    stream << "Perimeter: " << rhs.P_;
    return stream;
}
