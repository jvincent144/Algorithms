#include "matrixOps.h"

// Allocation
int** createArray(int rows, int cols, int val)
{
    // Array of pointers
    int** arr = new (std::nothrow) int* [rows];
    for(int i = 0; i < rows; i++)
    {
        // Array of integers
        arr[i] = new (std::nothrow) int [cols];
        // Assignment
        for(int j = 0; j < cols; j++)
        {
            arr[i][j] = val;
        }
    }
    return arr;
}

// Cleaning
void deleteArray(int** arr, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
}

void matrix::setRows(int rows)
    {
        this -> rows = rows;
    }

void matrix::setCols(int cols)
    {
        this -> cols = cols;
    }

int matrix::getRows()
    {
        return this -> rows;
    }

int matrix::getCols()
    {
        return this -> cols;
    }

void matrix::setValues(int** arr)
    {
        this -> values = arr;
    }

void matrix::deleteValues()
    {
        deleteArray(this -> values, this -> rows, this -> cols);
    }

void matrix::print()
    {
        for(int i = 0; i < this -> rows; i++)
        {
            for(int j = 0; j < this -> cols; j++)
            {
                std::cout << this -> values[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

matrix matrix::operator+(matrix b)
    {
        matrix a = *this;
        matrix c;
        
        // Allocation
        int** arr = createArray(a.getRows(), a.getCols(), 0);

        c.setRows(a.getRows());
        c.setCols(a.getCols());
        c.setValues(arr);

        for(int i = 0; i < a.getRows(); i++)
        {
            for(int j = 0; j < b.getRows(); j++)
            {
                c.values[i][j] = a.values[i][j] + b.values[i][j];
            }
        }

        return c;
    }

matrix partition(matrix c, int numberOfParts, int rowSelect, int colSelect)
{
    matrix part;
    part.setRows(c.getRows()/numberOfParts);
    part.setCols(c.getCols()/numberOfParts);
    int** arr = createArray(part.getRows(), part.getCols(), 0);
    part.setValues(arr);
    for(int i = rowSelect*part.getRows(); i < (rowSelect + 1)*part.getRows(); i++)
    {
        for(int j = colSelect*part.getCols(); j < (colSelect + 1)*part.getCols(); j++)
        {
            part.values[i - rowSelect*part.getRows()][j - colSelect*part.getCols()] = c.values[i][j];
        }
    }
    return part;
}

matrix combine(matrix a, matrix b, matrix c, matrix d)
{
    matrix combo;
    combo.setRows(a.getRows() + c.getRows());
    combo.setCols(a.getCols() + b.getCols());
    int** arr = createArray(combo.getRows(), combo.getCols(), 0);
    combo.setValues(arr);
    for(int i = 0; i < a.getRows(); i++)
    {
        for(int j = 0; j < a.getCols(); j++)
        {
            combo.values[i][j] = a.values[i][j];
            combo.values[i][j + a.getCols()] = b.values[i][j];
            combo.values[i + a.getRows()][j] = c.values[i][j];
            combo.values[i + a.getRows()][j + a.getCols()] = d.values[i][j];
        }
    }
    return combo;
}

matrix matmul(matrix a, matrix b)
{
    matrix c;
    if(1 == a.getRows())
    {
        // Base case
        c.setRows(1);
        c.setCols(1);
        int** arr = createArray(1, 1, 0);
        c.setValues(arr);
        c.values[0][0] = a.values[0][0]*b.values[0][0];
    }
    else
    {
        // Upper left partition
        matrix a00 = partition(a, 2, 0, 0);
        matrix b00 = partition(b, 2, 0, 0);

        // Upper right partition
        matrix a01 = partition(a, 2, 0, 1);
        matrix b01 = partition(b, 2, 0, 1);

        // Lower left partition
        matrix a10 = partition(a, 2, 1, 0);
        matrix b10 = partition(b, 2, 1, 0);

        // Lower right partition
        matrix a11 = partition(a, 2, 1, 1);
        matrix b11 = partition(b, 2, 1, 1);

        // Recursion
        matrix c00 = matmul(a00, b00) + matmul(a01, b10);
        matrix c01 = matmul(a00, b01) + matmul(a01, b11);
        matrix c10 = matmul(a10, b00) + matmul(a11, b10);
        matrix c11 = matmul(a10, b01) + matmul(a11, b11);

        // Combine partitions
        c = combine(c00, c01, c10, c11);

        // Cleaning
        a00.deleteValues();
        b00.deleteValues();
        c00.deleteValues();
        a01.deleteValues();
        b01.deleteValues();
        c01.deleteValues();
        a10.deleteValues();
        b10.deleteValues();
        c10.deleteValues();
        a11.deleteValues();
        b11.deleteValues();
        c11.deleteValues();
    }
    return c;
}