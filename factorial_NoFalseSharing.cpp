#include <iostream>
#include <omp.h>
using namespace std;
/*
Factorial parallel no false sharing
it take   0.0004062 sec
*/
int main()
{
    long n;
    int nthreads;

    cout << "please enter N numbers to calculate factorial for it : " << endl;
    cin >> n;

    long fact[2][8];
    for (int i = 0; i < 2; i++)
    {
        fact[i][0] = 1;
    }
    double STime = omp_get_wtime();
#pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        nthreads = omp_get_num_threads();

        for (int i = id + 1; i <= n; i += nthreads)
        {
            fact[id][0] *= i;
        }


    }
    long result = 1;

    for (int i = 0; i < 2; i++)
    {
        result *= fact[i][0];
    }
    double ETime = omp_get_wtime();
    double TakenTime = ETime - STime;
    cout << "The fact of the  " << n << " integers is: " << result << endl;
    cout << "Taken Time :  =  " << TakenTime << endl;
    return 0;
}