#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

template<typename T>
typename T::iterator easyfind(T &container, int target) {
    typename T::iterator result = std::find(container.begin(), container.end(), target);
    if (result == container.end())
        throw std::exception();
    return result;
}

template<typename T>
typename T::const_iterator easyfind(const T &container, int target) {
    typename T::const_iterator result = std::find(container.begin(), container.end(), target);
    if (result == container.end())
        throw std::exception();
    return result;
}

#endif
