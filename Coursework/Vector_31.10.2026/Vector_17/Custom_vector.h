
#include <iostream>
#include <exception>

class CustomVector
{
private:
    int _size;
    double *elem;

public:
    CustomVector(int size);
    ~CustomVector();

    int get_size();
    double get(int n);
    void set(int n, double value);
};

inline CustomVector::CustomVector(int size) : _size(size), elem(new double[size])
{
    for (int i = 0; i < _size; i++)
    {
        elem[i] = 0;
    }
}

inline CustomVector::~CustomVector()
{
    delete[] elem;
}

inline int CustomVector::get_size()
{
    return _size;
}

inline double CustomVector::get(int n)
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
