#include "maxSubarray.h"
#include <limits>

#define UNASSIGNED -1
#define SENTINEL std::numeric_limits<int>::min()

// Argument: Array size
node* createRoot(int size)
{
    node* pRoot = (node*) malloc(sizeof(node));
    pRoot -> leftBound = 0;
    pRoot -> rightBound = size - 1;
    pRoot -> sum = UNASSIGNED;
    return pRoot;
}

// Argument: Pointer to root node
void upRoot(node* pRoot)
{
    free(pRoot);
}

// Arguments:
node* createNode(int low, int high)
{
    node* pNode = (node*) malloc(sizeof(node));
    pNode -> leftBound = low;
    pNode -> rightBound = high;
    pNode -> sum = UNASSIGNED;
    return pNode;
}

// Argument: Pointer to node
void deleteNode(node* pNode)
{
    free(pNode);
}

// Arguments:
node* findMaxCrossSubarray(int* arr, node* pNode)
{
    // Calculate midpoint
    int mid = ((pNode -> leftBound) + (pNode -> rightBound))/2;

    int leftSum = SENTINEL;
    int rightSum = SENTINEL;

    // Updated bounds
    int leftMax = (pNode -> leftBound);
    int rightMax = (pNode -> rightBound);

    // Left of midpoint
    int sum = 0;
    for(int i = mid; i >= (pNode -> leftBound); i--)
    {
        sum += *(arr + i);
        if(sum > leftSum)
        {
            leftSum = sum;
            leftMax = i;
        }
    }

    // Right of midpoint
    sum = 0;
    for(int j = mid + 1; j <= (pNode -> rightBound); j++)
    {
        sum += *(arr + j);
        if(sum > rightSum)
        {
            rightSum = sum;
            rightMax = j;
        }
    }

    // Update node information at the end to avoid conflicts with loop conditions
    pNode -> leftBound = leftMax;
    pNode -> rightBound = rightMax;
    pNode -> sum = leftSum + rightSum;
    return pNode;
}

// Arguments: The array to analyze & the node, containing the indices of the subarray, the sum, etc.
node* findMaxSubarray(int* arr, node* pNode)
{
    // Condition: Subarray size == 1
    if((pNode -> leftBound) == (pNode -> rightBound))
    {
        // Assign sum
        pNode -> sum = *(arr + (pNode -> leftBound));
    }
    else
    {
        // Calculate midpoint
        int mid = ((pNode -> leftBound) + (pNode -> rightBound))/2;
        
        // Divide into left subarray
        node* pLeftSubarray = createNode(pNode -> leftBound, mid);
        pLeftSubarray = findMaxSubarray(arr, pLeftSubarray);
        
        // Divide into right subarray
        node* pRightSubarray = createNode(mid + 1, pNode -> rightBound);
        pRightSubarray = findMaxSubarray(arr, pRightSubarray);

        // Calculate the sum across the midpoint
        pNode = findMaxCrossSubarray(arr, pNode);
        
        // Find the greatest sum
        if((pLeftSubarray -> sum) >= (pRightSubarray -> sum) && (pLeftSubarray -> sum) >= (pNode -> sum))
        {
            // Update pNode
            pNode -> leftBound = pLeftSubarray -> leftBound;
            pNode -> rightBound = pLeftSubarray -> rightBound;
            pNode -> sum = pLeftSubarray -> sum;
        }
        else if((pRightSubarray -> sum) >= (pLeftSubarray -> sum) && (pRightSubarray -> sum) >= (pNode -> sum))
        {
            // Update pNode
            pNode -> leftBound = pRightSubarray -> leftBound;
            pNode -> rightBound = pRightSubarray -> rightBound;
            pNode -> sum = pLeftSubarray -> sum;
        }

        // Clean as you go
        deleteNode(pLeftSubarray);
        deleteNode(pRightSubarray);
    }

    // Return updated node
    return pNode;
}