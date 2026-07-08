#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array {
    private:
        T* data;
        unsigned int s;
    public:
        Array();
        Array(const Array& copy);
        Array(unsigned int s);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
};

template<typename T>
Array<T>::Array() : data(NULL), s(0)
{
}

template<typename T>
Array<T>::Array(unsigned int size) : data(NULL), s(size)
{
    if (s > 0)
        data = new T[s]();
}

template<typename T>
Array<T>::Array(const Array& copy) : data(NULL), s(copy.s)
{
    if (s > 0)
    {
        data = new T[s];
        for (unsigned int i = 0; i < s; ++i)
            data[i] = copy.data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] data;
        s = other.s;
        data = NULL;
        if (s > 0)
        {
            data = new T[s];
            for (unsigned int i = 0; i < s; ++i)
                data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array()
{
    delete[] data;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= s)
        throw std::out_of_range("index is out of range");
    return data[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= s)
        throw std::out_of_range("index is out of range");
    return data[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
    return s;
}

#endif