#include <iostream> 
#include <omp.h>

using namespace std;
/*
 * multiply the elements of an array reduction
 */
int main()
{
    const int n = 5;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the array element " << i + 1 << ": " << endl;
        cin >> arr[i];
    }

    int product = 1;
    double STime = omp_get_wtime();

#pragma omp parallel for reduction(*:product) num_threads(2)
    for (int i = 0; i < n; i++) {
        product *= arr[i];
    }

    double ETime = omp_get_wtime();
    float TakenTime = ETime - STime;
    cout << "The product of the array elements is: " << product << endl;
    cout << "Taken Time: " << TakenTime << " seconds" << endl;
    return 0;
}
