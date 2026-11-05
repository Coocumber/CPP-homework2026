#include <iostream>
#include <stdexcept>
#include <memory>

// template <typename T, size_t size = 0>
template <typename T, typename A = std::allocator<T>>
class CustomVector
{
private:
    A alloc;
    int size_;
    T *elem;
    int capacity_;

public:
    CustomVector();
    explicit CustomVector(int size, T def = T());
    CustomVector(std::initializer_list<T> lst);
    ~CustomVector();
    CustomVector(const CustomVector &other);
    CustomVector(CustomVector &&other) noexcept;
    CustomVector &operator=(const CustomVector &other);
    CustomVector &operator=(CustomVector &&other) noexcept;

    int size() const;
    int capacity() const;

    void reserve(int n);
    void resize(int n, T val = T());
    void push_back(T n);

    T &operator[](int n);
    const T &operator[](int n) const;
    T &at(int n);
    const T &at(int n) const;
};

template <typename T, typename A>
inline CustomVector<T, A>::CustomVector() : size_(0), elem(nullptr), capacity_(0)
{
}

template <typename T, typename A>
inline CustomVector<T, A>::CustomVector(int size, T def) : size_(size), elem(alloc.allocate(size)), capacity_(size)
{
    for (int i = 0; i < size_; i++)
    {
        elem[i] = def;
    }
}

template <typename T, typename A>
inline CustomVector<T, A>::CustomVector(std::initializer_list<T> lst) : size_(lst.size()), elem(alloc.allocate(lst.size())), capacity_(lst.size())
{
    std::copy(lst.begin(), lst.end(), elem);
}

template <typename T, typename A>
inline CustomVector<T, A>::~CustomVector()
{
    delete[] elem;
}

template <typename T, typename A>
inline CustomVector<T, A>::CustomVector(const CustomVector &other) : size_(other.size_), elem(alloc.allocate(other.size_)), capacity_(other.capacity_)
{
    for (int i = 0; i < other.size(); i++)
    {
        elem[i] = other.elem[i];
    }
}

template <typename T, typename A>
inline CustomVector<T, A>::CustomVector(CustomVector &&other) noexcept : size_(other.size_), elem(other.elem)
{
    delete[] elem;
    elem = other.elem;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.size_ = 0;
    other.capacity_ = 0;
    other.elem = nullptr;
}

template <typename T, typename A>
inline CustomVector<T, A> &CustomVector<T, A>::operator=(const CustomVector &other)
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

    T *p = alloc.allocate(other.size_);
    for (int i = 0; i < other.size_; i++)
    {
        p[i] = other.elem[i];
    }
    delete[] elem;
    elem = p;
    size_ = capacity_ = other.size_;
    return *this;
}

template <typename T, typename A>
inline CustomVector<T, A> &CustomVector<T, A>::operator=(CustomVector &&other) noexcept
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

template <typename T, typename A>
inline int CustomVector<T, A>::size() const
{
    return size_;
}

template <typename T, typename A>
inline int CustomVector<T, A>::capacity() const
{
    return capacity_;
}

template <typename T, typename A>
inline void CustomVector<T, A>::reserve(int n)
{
    if (n <= capacity_)
        return;
    T *p = alloc.allocate(n);
    for (int i = 0; i < size_; i++)
        alloc.construct(&p, elem[i]);
    for (int i = 0; i < size_; i++)
        alloc.destroy(&elem[i]);
    alloc.dealocate(elem, capacity_);
    elem = p;
    capacity_ = n;
}

template <typename T, typename A>
inline void CustomVector<T, A>::resize(int n, T val)
{
    reserve(n);
    for (int i = 0; i < n; i++)
        alloc.construct(&elem[i], val);
    for (int i = n; i < size_; i++)
        alloc.destroy(&elem[i]);
    size_ = n;
}

template <typename T, typename A>
inline void CustomVector<T, A>::push_back(T n)
{
    if (capacity_ == 0)
        reserve(8);
    else if (size_ == capacity_)
        reserve(2 * capacity_);
    alloc.construct(&elem[size_], n);
    ++size_;
}

template <typename T, typename A>
inline T &CustomVector<T, A>::operator[](int n)
{
    return elem[n];
}

template <typename T, typename A>
inline const T &CustomVector<T, A>::operator[](int n) const
{
    return elem[n];
}

template <typename T, typename A>
inline T &CustomVector<T, A>::at(int n)
{
    if (!(0 <= n && n < size_))
    {
        throw std::out_of_range("index out of range");
    }

    return elem[n];
}

// template<typename T, typename A>
// inline const T & CustomVector<T, A>::at(int n) const
// {
//     if (!(0 <= n && n < size_))
//     {
//         throw std::out_of_range("index out of range");
//     }

//     return elem[n];
// }