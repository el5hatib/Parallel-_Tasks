#include <iostream> 
#include <omp.h>

using namespace std;
/*

Summation of N numbers using reduction 
*/

int main()
{
    long n;
    cout << "Please enter N numbers to sum it: " << endl;
    cin >> n;
    long sum = 0;
    double STime = omp_get_wtime();

#pragma omp parallel num_threads(2)
    {
#pragma omp for reduction(+:sum)
        for (int i = 0; i < n; i++)
        {
            sum += i;
        }
    }

    double ETime = omp_get_wtime();
    double TakenTime = ETime - STime;

    cout << "The result is =  " << sum << endl;
    cout << "Taken Time :  =  " << TakenTime << endl;

    return 0;
}
