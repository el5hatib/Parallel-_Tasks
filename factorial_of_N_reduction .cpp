#include <iostream> 
#include <omp.h>

using namespace std;
/*Calculate Factorial of N using Reduction*/
int main()
{
    long n;
    cout << "Please enter N to calculate its factorial: " << endl;
    cin >> n;
    long fact = 1;
    double STime = omp_get_wtime();

#pragma omp parallel 
    {
#pragma omp for reduction (*:fact)
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
        }
    }

    double ETime = omp_get_wtime();
    double TakenTime = ETime - STime;

    cout << "The factorial of " << n << " is " << fact << endl;
    cout << "Time taken: " << TakenTime << " seconds" << endl;

    return 0;
}
