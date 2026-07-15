#ifndef ARRAY_HPP
#define ARRAY_HPP

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

#endif