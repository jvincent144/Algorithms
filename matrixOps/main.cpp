#include "matrixOps.h"

# define SIZE 4

int main()
{
    int** arr1 = createArray(SIZE, SIZE, 1);
    int** arr2 = createArray(SIZE, SIZE, 2);
    int** arr3 = createArray(SIZE, SIZE, 0);

    matrix a;
    a.setRows(SIZE);
    a.setCols(SIZE);
    a.setValues(arr1);
    a.print();

    matrix b;
    b.setRows(SIZE);
    b.setCols(SIZE);
    b.setValues(arr2);
    b.print();

    matrix c;
    c.setRows(SIZE);
    c.setCols(SIZE);
    c.setValues(arr3);

    c = matmul(a, b);
    c.print();

    // Can't delete both blocks; they point to the same space.
    // deleteArray(arr1, SIZE, SIZE);
    // deleteArray(arr2, SIZE, SIZE);
    // deleteArray(arr3, SIZE, SIZE);

    a.deleteValues();
    b.deleteValues();
    c.deleteValues();

    return 0;
}