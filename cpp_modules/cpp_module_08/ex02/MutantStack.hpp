#pragma once

#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T>> {
public:
    // Type aliases for external use
    using iterator = typename std::deque<T>::iterator;
    using const_iterator = typename std::deque<T>::const_iterator;
    using reverse_iterator = typename std::deque<T>::reverse_iterator;
    using const_reverse_iterator = typename std::deque<T>::const_reverse_iterator;

    // Constructors
    MutantStack() : std::stack<T, std::deque<T>>() {}
    MutantStack(const MutantStack& other) : std::stack<T, std::deque<T>>(other) {}
    MutantStack& operator=(const MutantStack& other) {
        std::stack<T, std::deque<T>>::operator=(other);
        return *this;
    }
    ~MutantStack() = default;

    // Iterators
    iterator begin()       { return this->c.begin(); }
    iterator end()         { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end()   const { return this->c.end(); }

    reverse_iterator rbegin()       { return this->c.rbegin(); }
    reverse_iterator rend()         { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend()   const { return this->c.rend(); }
};