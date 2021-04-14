#include <iostream>
#include <cstdlib>

typedef struct
{
    // Assign upon node creation
    int leftBound;
    int rightBound;

    // Assign in base case & "findMaxCrossingSubarray()"
    int sum;
} node;

node* createRoot(int);

void upRoot(node*);

node* findMaxSubarray(int*, node*);