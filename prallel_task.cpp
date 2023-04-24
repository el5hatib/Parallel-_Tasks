#include <iostream>
#include <omp.h>
using namespace std;

/*
 * summ elemnts of array using parallel task
 *
 *
 */
int main() {
    int n = 100;
    int s = 25;
    int result = 0;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }

#pragma omp parallel shared(result) num_threads(4)
    {
#pragma omp single
        {
            for (int i = 0; i < n; i += s)
            {
                int start = i;
                int end = i + s - 1;
#pragma omp task shared(result)
                {
                    int sum = 0;
                    for (int j = start; j <= end; j++)
                    {
                        sum += a[j];
                    }
#pragma omp critical
                    {
                        result += sum;
                    }
                }
            }
        }
    }
    cout << "sum = " << result << endl;
    return 0;
}
