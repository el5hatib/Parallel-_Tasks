#include <iostream>
#include <omp.h>
#include <cstdlib>
using namespace std;
/* 
Multiply Vector by matrix Parallel
*/
int main()
{
    int sum=0;
    int arr[3][2];
    int vect[3];
    int result[3] = { 0,0,0 };
    // Initialize matrix  with random values
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr[i][j] = rand();
        }
    }
    // Initialize vector with random values
    for (int i = 0; i < 3; i++) {
        vect[i] = rand();
    }


    float STime = omp_get_wtime(); 
  // Compute the matrix-vector multiplication using OpenMP
#pragma omp parallel for reduction(+:sum)  num_threads(2)
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                sum += arr[i][j] * vect[i];
                result[i] = sum;
            }
        }
    float TakenTime = omp_get_wtime()-STime;
    // Print the result
    for (int i = 0; i < 3; i++)
    {
        cout << result[i] << " " <<endl ;
    }
    cout << "Taken Time = " << TakenTime << "  Secondes" << endl;

    return 0;
}
