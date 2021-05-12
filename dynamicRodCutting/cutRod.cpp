#include "cutRod.h"

// Naive implementation
int cutRod(int* p, int n)
{
    // If the rod size is zero, the revenue is zero.
    if(0 == n)
    {
        return 0;
    }
    
    int q = std::numeric_limits<int>::min(); // Minimum signed integer
    int temp;
    for(int i = 0; i < n; i++)
    {
        temp = p[i] + cutRod(p, n - i - 1);
        if(q < temp)
        {
            q = temp;
        }
    }
    return q;
}

/*
// Segmentation fault: 11
// Does it reach the base case?
// No.
// Does n decrease?
// No.
// Why?
// Index i starts at 0. Therefore, n - i is still n.
// Therefore, the algorithm never gets past the first step.
// What is the solution?
// Change the argument from n - i to n - i - 1.
*/

// Top-Down Approach Through Memoization
int memoCutRodAux(int* p, int n, int* r)
{
    // If memoized, return the memoized value
    if(0 <= r[n])
    {
        return r[n];
    }

    int q = std::numeric_limits<int>::min();
    // Base case
    if(0 == n)
    {
        q = 0;
    }   
    else
    {
        int temp;
        for(int i = 0; i < n; i ++)
        {
            temp = p[i] + memoCutRodAux(p, n - i - 1, r);
            if(q < temp)
            {
                q = temp;
            }
        }
    }
    r[n] = q;
    
    return q;
}

int memoCutRod(int* p, int n)
{
    int* r = new (std::nothrow) int[n + 1]; // Includes the case where n equals zero
    for(int i = 0; i <= n; i++)
    {
        r[i] = std::numeric_limits<int>::min();
    }
    int optimalRev = memoCutRodAux(p, n, r);
    delete [] r;
    return optimalRev;
}

// Bottom-Up Implementation
int bottomUpCutRod(int* p, int n)
{
    int* r = new (std::nothrow) int[n + 1]; // Maximum revenue from the visited subproblems
    r[0] = 0;
    int q;
    int temp;

    // For various lengths of the total rod
    for(int j = 1; j <= n; j++)
    {
        q = std::numeric_limits<int>::min();
        // For various lengths of the cut rod
        for(int i = 0; i < j; i++)
        // for(int i = 1; i <= j; i++)
        {
            temp = p[i] + r[j - i - 1];
            // temp = p[i - 1] + r[j - i];
            // r[j - i] is the maximum revenue from the previously visited subproblem, which already includes the sub-subproblems
            if(q < temp)
            {
                q = temp;
            }
        }
        r[j] = q; // Assign the maximum revenue for this subproblem
    }

    temp = r[n]; // r[n] represents the maximum revenue out of all the visited subproblems
    delete [] r;
    return temp;
}