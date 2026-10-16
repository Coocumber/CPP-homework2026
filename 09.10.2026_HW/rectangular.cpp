#include "shape.h"

Rectangular::Rectangular(std::string name, double weight, double hight)
    : weight_(weight), hight_(hight)
{
    if (weight_ <= 0 || hight_ <= 0)
    {
        throw std::range_error("not a rectangular");
    }
    name_ = name;
    S_ = weight_ * hight_;
    P_ = (weight_ + hight_) * 2;
}

double Rectangular::area()
{
    return S_;
}

double Rectangular::perimeter()
{
    return P_;
}

Rectangular::Rectangular(const Rectangular &other)
{
    name_ = other.name_;
    weight_ = other.weight_;
    hight_ = other.hight_;
    S_ = other.S_;
    P_ = other.P_;
}

Rectangular::Rectangular(Rectangular &&other)
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
}

Rectangular &Rectangular::operator=(const Rectangular &other)
{
    name_ = other.name_;
    weight_ = other.weight_;
    hight_ = other.hight_;
    S_ = other.S_;
    P_ = other.P_;
    return *this;
}

Rectangular &Rectangular::operator=(Rectangular &&other)
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

std::ostream &operator<<(std::ostream &stream, const Rectangular &rhs)
{
    stream << "Figure: " << rhs.name_ << " | ";
    stream << "Figure_size " << rhs.weight_ << ", " << rhs.hight_ << " | ";
    stream << "Area: " << rhs.S_ << " | ";
    stream << "Perimeter: " << rhs.P_;
    return stream;
}
