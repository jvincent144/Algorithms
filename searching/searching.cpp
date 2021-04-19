#include <iostream>

int binSearch(int* arr, int lb, int ub, int c)
{
    if(lb == ub)
    {
        if(arr[lb] == c)
        {
            return lb;
        }
        else
        {
            return -1;
        }
    }

    int mid = (ub + lb)/2;
    if(c <= arr[mid])
    {
        return binSearch(arr, lb, mid, c);
    }
    else
    {
        return binSearch(arr, mid + 1, ub, c);
    }
}