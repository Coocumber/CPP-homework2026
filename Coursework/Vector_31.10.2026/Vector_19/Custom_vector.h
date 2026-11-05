#include <iostream>
#include <exception>

template <typename T, size_t size = 0>
class CustomVector
{
private:
    int size_;
    T *elem;
    int capacity_;

public:
    CustomVector();
    explicit CustomVector(int size, T def = T);
    CustomVector(std::initializer_list<T> lst);
    ~CustomVector();
    CustomVector(const CustomVector &other);
    CustomVector(CustomVector &&other) noexcept;
    CustomVector &operator=(const CustomVector &other);
    CustomVector &operator=(CustomVector &&other) noexcept;

    int size() const;
    int capacity() const;

    void reserve(int n);
    void resize(int n);
    void push_back(T n);

    T &operator[](int n);
    const T &operator[](int n) const;
};

template <typename T, size_t size>
inline CustomVector<T, size>::CustomVector() : size_(0), elem(nullptr), capacity_(0)
{
}

template <typename T, size_t size>
inline CustomVector<T, size>::CustomVector(int size, T def = T) : size_(size), elem(new T[size]), capacity_(size)
{
    for (int i = 0; i < size_; i++)
    {
        elem[i] = def;
    }
}

template <typename T, size_t size>
inline CustomVector<T, size>::CustomVector(std::initializer_list<T> lst) : size_(lst.size()), elem(new T[lst.size()]), capacity_(lst.size())
{
    std::copy(lst.begin(), lst.end(), elem);
}

template <typename T, size_t size>
inline CustomVector<T, size>::~CustomVector()
{
    delete[] elem;
}

template <typename T, size_t size>
inline CustomVector<T, size>::CustomVector(const CustomVector &other) : size_(other.size_), elem(new T[other.size_]), capacity_(other.capacity_)
{
    for (int i = 0; i < other.size(); i++)
    {
        elem[i] = other.elem[i];
    }
}

template <typename T, size_t size>
inline CustomVector<T, size>::CustomVector(CustomVector &&other) noexcept : size_(other.size_), elem(other.elem)
{
    delete[] elem;
    elem = other.elem;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.size_ = 0;
    other.capacity_ = 0;
    other.elem = nullptr;
}

template <typename T, size_t size>
inline CustomVector<T, size> &CustomVector<T, size>::operator=(const CustomVector &other)
{
    if (this == &other)
        return *this;

    if (other.capacity_ <= capacity_)
    {
        for (int i = 0; i < other.size_; i++)
        {
            elem[i] = other.elem[i];
        }
        size_ = other.size_;
        return *this;
    }

    T *p = new T[other.size_];
    for (int i = 0; i < other.size_; i++)
    {
        p[i] = other.elem[i];
    }
    delete[] elem;
    elem = p;
    size_ = capacity_ = other.size_;
    return *this;
}

template <typename T, size_t size>
inline CustomVector<T, size> &CustomVector<T, size>::operator=(CustomVector &&other) noexcept
{
    delete[] elem;
    elem = other.elem;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.elem = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
    return *this;
}

template <typename T, size_t size>
inline int CustomVector<T, size>::size() const
{
    return size_;
}

template <typename T, size_t size>
inline int CustomVector<T, size>::capacity() const
{
    return capacity_;
}

template <typename T, size_t size>
inline void CustomVector<T, size>::reserve(int n)
{
    if (n <= capacity_)
        return;
    T *p = new T[n];
    for (int i = 0; i < size_; i++)
    {
        p[i] = elem[i];
    }
    delete[] elem;
    elem = p;
    capacity_ = n;
}

template <typename T, size_t size>
inline void CustomVector<T, size>::resize(int n)
{
    reserve(n);
    for (int i = size_; i < n; i++)
    {
        elem[i] = 0;
    }
    size_ = n;
}

template <typename T, size_t size>
inline void CustomVector<T, size>::push_back(T n)
{
    if (capacity_ == 0)
        reserve(8);
    else if (size_ == capacity_)
        reserve(2 * capacity_);
    elem[size_] = n;
    ++size_;
}

template <typename T, size_t size>
inline T &CustomVector<T, size>::operator[](int n)
{
    if (!(0 <= n && n < size_))
    {
        throw std::out_of_range("index out of range");
    }

    return elem[n];
}

template <typename T, size_t size>
inline const T &CustomVector<T, size>::operator[](int n) const
{
    if (!(0 <= n && n < size_))
    {
        throw std::out_of_range("index out of range");
    }

    return elem[n];
}