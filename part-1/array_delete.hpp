#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <utility>
#include <vector>

template <typename T>
void array_delete(std::vector<T> &A, std::size_t index)
{
    std::vector<T>::iterator i;
    for (i = index ; i < sizeof(A) - index ; i++)
    {
        A[i] = A[i + 1];
    }
    A[i] = [];
}

#endif // __array_delete__