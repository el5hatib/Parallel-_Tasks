#include <iostream>
#include <omp.h>
using namespace std;
/* Summation of n Numbers Parallel
* No False Sharing 
* Time of 100000000 is = 0.388216
*/
int main()
{
    long n;
    int nthreads;

    cout << "Please enter the number of integers to sum: " << endl;
    cin >> n;

    double sum[2][8];
    for (int i = 0; i < 2; i++)
    {
        sum[i][0] = 0;
    }
    double STime = omp_get_wtime();
#pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        nthreads = omp_get_num_threads();

        for (int i = id + 1; i <= n; i += nthreads)
        {
            sum[id][0] += i;
        }


    }
    long result = 0;

    for (int i = 0; i < 2; i++)
    {
        result += sum[i][0];
    }
    double ETime = omp_get_wtime();
    double TakenTime = ETime - STime;
    cout << "The sum of the first " << n << " integers is: " << result << endl;
    cout << "Taken Time :  =  " << TakenTime << endl;
    return 0;
}
