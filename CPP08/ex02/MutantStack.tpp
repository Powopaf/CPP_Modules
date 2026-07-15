#include <iterator>
#include <stack>

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
    std::stack<T>::operator=(other);
    return *this;
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
    return this->c.end();
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin() {
    return this->c.rbegin();
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend() {
    return this->c.rend();
}


