#include <iostream>
#include <omp.h>

using namespace std;

/* Summation of n Numbers Parallel
* Synchronization
*/
int main() {
    double result = 0;
    long n;
    cout << "Please enter the number of integers to sum: " << endl;
    cin >> n;
    double STime = omp_get_wtime();

#pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();
        double sum = 0;

        for (int i = id + 1; i <= n; i += nthreads) {
            sum += i;
        }

#pragma atomic  // or #pragma omp critical  or #pragma omp barrier
        {
            result += sum;
        }
    }

    double ETime = omp_get_wtime();
    double TakenTime = ETime - STime;
    cout << "The sum of the first " << n << " integers is: " << result << endl;
    cout << "Taken Time: " << TakenTime << " seconds." << endl;
    return 0;
}
