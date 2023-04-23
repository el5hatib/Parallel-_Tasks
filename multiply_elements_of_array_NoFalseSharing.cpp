#include <iostream>
#include <omp.h>
using namespace std;
/* multiply elements of arrays Parallel 
* no false haring
*/
int main()
{
    
    const int n = 5;
    int arr[n][8];
    long multiply[2][8];
    for (int i = 0; i < 2; i++)
    {
        multiply[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter the array elements of  " << i + 1 << ": " << endl;
        cin >> arr[i][0];
    }
    double STime = omp_get_wtime();
#pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();
        for (int i = id; i < n; i += nthreads)
        {

            multiply[id][0] = arr[i][0]* multiply[id][0];

        }// end of for loob in paragma 
    }// end of pragma
    int result = 1;
    for (int i = 0; i < 2; i++)
    {
        result = multiply[i][0] * result;
    }
    double ETime = omp_get_wtime();
    double TakenTime = ETime - STime;
    cout << "The Result of Multiply is =  : " << result << endl;
    cout << "Taken Time :  =  " << TakenTime << endl;

    return 0;
}// end of main function