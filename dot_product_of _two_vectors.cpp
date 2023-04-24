#include <iostream>
#include <omp.h>
#include <cstdlib>

using namespace std;
/*
 * The dot product of two vectors 
 */
int main()
{
    int sum = 0;
    int vect1[3], vect2[3];
    int vect3[3] = { 1,1,1 };

    // Initialize the vectors
    for (int i = 0; i < 3; i++)
    {
        vect1[i] = rand();
        vect2[i] = rand();
    }
    double start = omp_get_wtime();
#pragma omp parallel for num_threads(2) reduction(+:sum) 
    for (int i = 0; i < 3; i++)
    {
        vect3[i] = vect1[i] * vect2[i];
        sum += vect3[i];
    }
    double end = omp_get_wtime();
    double time = end - start;

    cout << "The dot product of the vectors is " << sum << endl;
    cout << "The time taken is " << time <<"  Seconds" << endl;

    return 0;
}
