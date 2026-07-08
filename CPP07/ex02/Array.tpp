#include "Array.hpp"
#include <stdexcept>

template<typename T>
Array<T>::Array(){
    data = NULL;
    s = 0;
}

template<typename T>
Array<T>::Array(unsigned int s) {
    this->s = s;
    if (s <= 0)
        data = NULL;
    else
        data = new T[this->s]();
}

template<typename T>
Array<T>::Array(const Array& copy) {
    s = copy.size();
    if (s <= 0)
        data = NULL;
    else {
        data = new T[this->s];
        for (unsigned int i = 0; i < s; i++)
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
        if (s == 0)
            data = NULL;
        else
        {
            data = new T[s];
            for (unsigned int i = 0; i < s; ++i)
                data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete [] data;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index < 0 || index > s)
        throw std::out_of_range("index is out of range");
    return data[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
        if (index < 0 || index > s)
        throw std::out_of_range("index is out of range");
    return data[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return s;
}