#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template<typename T>
int find(T container, int target) {
    int res = 0;
    typename T::iterator it = container.begin();
    while (it != container.end()) {
        if (*it == target)
            return res;
        it++;
        res++;
    }
    return -1;
}

#endif