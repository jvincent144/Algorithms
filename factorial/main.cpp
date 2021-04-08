// I/O
#include <iostream>

// System Status
#include <cstdlib>

// String Handling
#include <string>
#include <sstream>

int factorial(int);

int main(int argc, char* argv[])
{
    if(2 > argc)
    {
        std::cout << "Error:\tToo few arguments" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::stringstream ss(argv[argc - 1]);
    int n;
    ss >> n;
    std::cout << factorial(n) << std::endl;

    return 0;
}

// Proven recursive algorithm
int factorial(int n)
{
    if(1 < n)
    {
        return n*factorial(n-1);
    }
    else
    {
        return 1;
    }
}

// Proven loop invariant algorithm
/*
int factorial(int n)
{
    int result = 1;
    for(int i = 1; i < (n + 1); i++)
    {
        result *= i;
    }
    return result;
}
*/

// Implementation, requiring less memory
/*
int factorial(int n)
{
    int result = 1;
    while(1 < n)
    {
        result *= n;
        n--;
    }
    return result;
}
*/