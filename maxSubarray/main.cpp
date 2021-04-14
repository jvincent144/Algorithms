#include "maxSubarray.h"

int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    // int arr[] = {1};
    // int arr[] = {5, 4, -1, 7, 8};
    int size = sizeof(arr)/sizeof(int);
    node* pRoot = createRoot(size);
    pRoot = findMaxSubarray(arr, pRoot);
    std::cout << "Maximum sum:\t" << (pRoot -> sum) <<  std::endl;
    upRoot(pRoot);
    return 0;
}