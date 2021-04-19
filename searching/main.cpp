// I/O
#include <iostream>

// Random numbers
#include <cstdlib>

// Sorting
#include "../sorting/sorting.h"

// Searching
#include "searching.h"

#define SIZE 100

void fillRandomArray(int*, int);

void printArrayContents(int*, int);

int main()
{
    int arr[SIZE] = {};
    fillRandomArray(arr, SIZE);
    printArrayContents(arr, SIZE);
    msort(arr, 0, SIZE - 1);
    printArrayContents(arr, SIZE);
    std::cout << binSearch(arr, 0, SIZE - 1, 8) << std::endl;
    return 0;
}

void fillRandomArray(int* pFirstElement, int size)
{
    for(int i = 0; i < size; i++)
    {
        *(pFirstElement + i) = rand() % 100; // Generate a random integer between 0 and 99
    }
}

void printArrayContents(int* pFirstElement, int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << *(pFirstElement + i) << ' ';
    }
    std::cout << std::endl;
}