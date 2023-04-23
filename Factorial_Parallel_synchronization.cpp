#include <iostream>
#include <omp.h>

using namespace std;
/*

factorial parallel using synchronization
*/

int main()
{
    long n;
    int nthreads;
    long result = 1;
    cout << "please enter N numbers to calculate factorial for it : " << endl;
    cin >> n;

    long fact;
    double STime = omp_get_wtime();
#pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        long fact=1;

        for (int i = id + 1; i <= n; i += nthreads)
        {
            fact *= i;
        }

#pragma omp atomic  // or  #pragma omp critical or  #pragma omp barrier (but barrier not necessary )
        {
            result *= fact; 
        }
    }
    double ETime = omp_get_wtime();
    double TakenTime = ETime - STime;
    cout << "The fact of the  " << n << " integers is: " << result << endl;
    cout << "Taken Time :  =  " << TakenTime << endl;
    return 0;
}