#include <iostream>
#include <cstdlib>

// Allocation
int** createArray(int, int, int);

// Cleaning
void deleteArray(int**, int, int);

class matrix
{
    private:
        int rows;
        int cols;
    
    public:
        void setRows(int);
        void setCols(int);
        int getRows();
        int getCols();
        void setValues(int**);
        void deleteValues();
        void print();
        matrix operator+(matrix);

    int** values;
};

matrix partition(matrix, int, int, int);

matrix combine(matrix, matrix, matrix, matrix);

matrix matmul(matrix, matrix);