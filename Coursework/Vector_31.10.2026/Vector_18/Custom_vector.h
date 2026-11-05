#include <iostream>
#include <stdexcept>

class CustomVector
{
private:
    int _size;
    double *elem;

public:
    explicit CustomVector(int size);
    CustomVector(std::initializer_list<double> lst);
    ~CustomVector();
    CustomVector(const CustomVector &other);
    CustomVector(CustomVector &&other) noexcept;
    CustomVector &operator=(const CustomVector &other);
    CustomVector &operator=(CustomVector &&other) noexcept;

    int get_size() const;
    double get(int n) const;
    void set(int n, double value);
    double &operator[](int n);
    double operator[](int n) const;
};

CustomVector::CustomVector(int size) : _size(size), elem(new double[size])
{
    for (int i = 0; i < _size; i++)
    {
        elem[i] = 0;
    }
}

CustomVector::CustomVector(std::initializer_list<double> lst) : _size(lst.size()), elem(new double[lst.size()])
{
    std::copy(lst.begin(), lst.end(), elem);
}

CustomVector::~CustomVector()
{
    delete[] elem;
}

CustomVector::CustomVector(const CustomVector &other) : _size(other.get_size()), elem(new double[other.get_size()])
{
    // for (int i = 0; i < other.get_size(); i++)
    // {
    //     elem[i] = other.get(i);
    // }

    std::copy(other.elem, other.elem + other.get_size(), elem);
}

CustomVector::CustomVector(CustomVector &&other) : _size(other._size), elem(other.elem)
{
    other._size = 0;
    other.elem = nullptr;
}

CustomVector &CustomVector::operator=(const CustomVector &other)
{
    double *p = new double[other.get_size()];
    std::copy(other.elem, other.elem + other.get_size(), p);
    delete[] elem;
    elem = p;
    _size = other._size;
    return *this;
}

CustomVector &CustomVector::operator=(CustomVector &&other)
{
    delete[] elem;
    elem = other.elem;
    _size = other._size;
    other.elem = nullptr;
    other._size = 0;
    return *this;
}

inline int CustomVector::get_size() const
{
    return _size;
}

inline double CustomVector::get(int n) const
{
    if (!(0 <= n && n < _size))
    {
        throw std::out_of_range("index out of range");
    }
    return elem[n];
}

inline void CustomVector::set(int n, double value)
{
    if (!(0 <= n && n < _size))
    {
        throw std::out_of_range("index out of range");
    }
    elem[n] = value;
}

inline double &CustomVector::operator[](int n)
{
    if (!(0 <= n && n < _size))
    {
        throw std::out_of_range("index out of range");
    }

    return elem[n];
}

inline double CustomVector::operator[](int n) const
{
    if (!(0 <= n && n < _size))
    {
        throw std::out_of_range("index out of range");
    }

    return elem[n];
}