#include <iostream>
#include <omp.h>
#include <cstdlib>
using namespace std;

/*
 * N column of matrix A should be equal to N row of matrix B
 * The result of matrix multiplication is a matrix with N row of matrix A and N column of matrix B
 */
int main()
{
    int row_a = 2;
    int col_a = 3;
    int row_b = col_a;
    int col_b = 2;
    int a[2][3];
    int b[3][2];
    int c[2][2];

    double start_time = omp_get_wtime();

    // Initialize matrix A
    for (int i = 0; i < row_a; i++)
    {
        for (int j = 0; j < col_a; j++)
        {
            a[i][j] = rand();
        }
    }

    // Initialize matrix B
    for (int i = 0; i < row_b; i++)
    {
        for (int j = 0; j < col_b; j++)
        {
            b[i][j] = rand();
        }
    }

    // Matrix multiplication 
    for (int i = 0; i < row_a; i++)
    {
        for (int j = 0; j < col_b; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < col_a; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    double end_time = omp_get_wtime();

    // Print out the result
    for (int i = 0; i < row_a; i++)
    {
        for (int j = 0; j < col_b; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    // Print out the time
    cout << "Time: " << end_time - start_time << endl;

    return 0;
}
