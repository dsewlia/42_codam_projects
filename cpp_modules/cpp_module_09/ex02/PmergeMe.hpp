#pragma once

#include <ctime>
#include <sstream>
#include <vector>
#include <deque>


/*
    Template Ford-Johnson sorter (Merge-Insertion)
    Stores:
        - Sorted Container
        - Execution time (in microseconds)
        - NUmber of comparisons
*/

template <typename Container>
class PmergeMe
{
    private:
        Container   _data;
        long long   _time;
        long long   _comparisons;

    public:
        PmergeMe() : _time(0), _comparisons(0) {}
        ~PmergeMe() {}

        void sort(char **av)
        {
            clock_t start = clock();
            int size = 0;
            while (av[size + 1])
                size++;
            reserveIfVector(_data, size);
            for (int i = 1; av[i]; ++i)
            {
                std::stringstream ss(av[i]);
                int value;
                ss >> value;
                _data.push_back(value);
            }
            fordJohnson(_data);
            clock_t end = clock();
            _time = static_cast<long long>(
                ((double)(end - start) / CLOCKS_PER_SEC) * 1000000
            );
        }
        const Container &getSorted() const {return _data;}
        long long getTime() const {return _time;}
        long long getComparisons() const {return _comparisons;}

    private:
        void fordJohnson(Container &data)
        {
            if (data.size() <= 1)
                return;
            Container big;
            Container small;
            for (size_t i = 0; i < data.size() - 1; i+=2)
            {
                _comparisons++;
                if (data[i] > data[i + 1]) {
                    big.push_back(data[i]);
                    small.push_back(data[i + 1]);
                } else {
                    big.push_back(data[i + 1]);
                    small.push_back(data[i]);
                }
            }
            if (data.size() % 2 != 0)
                small.push_back(data.back());
            fordJohnson(big);
            size_t smallSize = small.size();
            for (size_t i = 0; i < smallSize; ++i)
                binaryInsert(big,small[i]);
            data = big;
        }

        void binaryInsert(Container &data, int value)
        {
            size_t left = 0;
            size_t right = data.size();
            while (left < right)
            {
                size_t mid = left + (right - left) / 2;
                _comparisons++;
                if (value < data[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            data.insert(data.begin() + left, value);
        }

        template<typename T>
        void reserveIfVector(T&,size_t) {}

        template<typename T>
        void reserveIfVector(std::vector<T> &v, size_t n) { v.reserve(n); }
};