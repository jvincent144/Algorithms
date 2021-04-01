// I/O
#include <iostream>

// Random numbers
#include <cstdlib>

// Measurements
#include <chrono>

// Custom sorting algorithms
#include "sorting.h"

#define SIZE 100

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

int main()
{
    int randomArray[SIZE] = {};
    fillRandomArray(randomArray, SIZE);
    printArrayContents(randomArray, SIZE);
    // isort(randomArray, SIZE);
    msort(randomArray, 0, SIZE - 1);
    printArrayContents(randomArray, SIZE);
    return 0;
}