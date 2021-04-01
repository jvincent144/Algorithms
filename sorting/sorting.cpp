// I/O
#include <iostream>

// Program status
#include <cstdlib>

// Maximum integer value
#define SENTINEL std::numeric_limits<int>::max();

void isort(int* pFirstElement, int size)
{
    if(NULL == pFirstElement)
    {
        std::cout << "In function, isort:\tInvalid input array" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 1; i < size; i++)
    {   
        int key = *(pFirstElement + i); // Current item

        int j = 0; // Indices left of current item
        while(*(pFirstElement + i - j - 1) > key)
        {
            *(pFirstElement + i - j) = *(pFirstElement + i - j - 1);
            j++;
        }
        *(pFirstElement + i - j) = key;
    }
}

void merge(int* pFirstElement, int p, int q, int r)
{
    if(NULL == pFirstElement)
    {
        std::cout << "In function, merge:\tInvalid input array" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    int n1 = q - p + 1; // Size of left + 1
    int n2 = r - q; // Size of right

    // +1 for sentinel
    int* pLeft = new (std::nothrow) int[n1 + 1];
    int* pRight = new (std::nothrow) int[n2 + 1];

    // Verify memory allocation
    if(NULL == pLeft || NULL == pRight)
    {
        std::cout << "In function, merge:\tFailed to allocate memory" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < n1; i++)
    {
        pLeft[i] = *(pFirstElement + p + i);
    }
    for(int j = 0; j < n2; j++)
    {
        pRight[j] = *(pFirstElement + q + j + 1);
    }

    // Insert sentinel
    pLeft[n1] = SENTINEL;
    pRight[n2] = SENTINEL;

    int i = 0;
    int j = 0;
    for(int k = p; k < (r + 1); k++)
    {
        if(pLeft[i] <= pRight[j])
        {
            *(pFirstElement + k) = pLeft[i];
            i++;
        }
        else
        {
            *(pFirstElement + k) = pRight[j];
            j++;
        }
    }

    // Cleaning
    delete[] pLeft;
    delete[] pRight;
}

void msort(int* pFirstElement, int p, int r)
{
    if(NULL == pFirstElement)
    {
        std::cout << "In function, msort:\tInvalid input array" << std::endl;
        exit(EXIT_FAILURE);
    }

    if(p < r)
    {
        // Divide & conquer
        int q = (p + r)/2; // Middle
        msort(pFirstElement, p, q); // Left
        msort(pFirstElement, q + 1, r); // Right
        merge(pFirstElement, p, q, r); // Combine
    }
    else
    {
        // Do nothing...
    }
}