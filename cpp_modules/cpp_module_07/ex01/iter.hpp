#pragma once

#include <cstdio>

template <typename T, typename F>
void iter(T *arr, const size_t &size, const F &func)
{
    for (size_t i = 0; i < size; i++)
    {
        func(arr[i]);
    }
}