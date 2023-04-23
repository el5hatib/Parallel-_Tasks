#include <iostream>
#include <omp.h>
using namespace std; 
int main()
{
    const int n = 5;
    int arr[n];
    int multiply[2] = { 1,1 };
    for (int i = 0; i < n; i++) {
        cout << "Enter the array elements of  " << i + 1 << ": " << endl;
        cin >> arr[i];
    }
    double STime = omp_get_wtime();
#pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num(); 
        int nthreads = omp_get_num_threads(); 
        for (int i = id; i <n; i += nthreads)
        {

            multiply[id] = arr[i] * multiply[id];

        }// end of for loob in paragma 
    }// end of pragma
    int result = 1; 
    for (int i = 0; i < 2; i++)
    {
        result = multiply[i] * result;
    }
    double ETime = omp_get_wtime();
    float TakenTime = ETime - STime;
    cout << "The Result of Multiply is =  : " << result << endl;
    cout << "Taken Time :  =  " << TakenTime << endl;
  
	return 0; 
}// end of main function