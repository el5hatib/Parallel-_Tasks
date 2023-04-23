#include <iostream>
#include <omp.h>
using namespace std;
/*
multiply array elements in parallel sychronization
*/

int main()
{
    const int n = 5;
    int arr[n];
    double result = 1.0; 
    for (int i = 0; i < n; i++) {
        cout << "Enter the array elements of  " << i + 1 << ": " << endl;
        cin >> arr[i];
    }
    double STime = omp_get_wtime();
#pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();
        double multiply = 1.0;
        for (int i = id; i < n; i += nthreads)
        {

            multiply = arr[i] * multiply;

        }// end of for loob in paragma 
#pragma  atomic  // or #pragma omp barrier , #pragma omp critical
        {
            result *= multiply;
        }
    }// end of pragma
    double ETime = omp_get_wtime();
    float TakenTime = ETime - STime;
    cout << "The Result of Multiply is =  : " << result << endl;
    cout << "Taken Time :  =  " << TakenTime << endl;

    return 0;
}// end of main function