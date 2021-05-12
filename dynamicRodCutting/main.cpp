#include "cutRod.h"

#define SIZE 4

int main()
{
    int prices[SIZE] = {1, 5, 8, 9};
    // int optimalRevenue = cutRod(prices, SIZE);
    // int optimalRev = memoCutRod(prices, SIZE);
    int optimalRev = bottomUpCutRod(prices, SIZE);
    std::cout << "The optimal revenue is:\t" << optimalRev << std::endl;
    return 0;
}