#include <iostream>
#include <omp.h>
using namespace std;

/*
 * Fibonacci Function using Parallel Task code (OpenMP)
 * in videos there are an error in the code because we should return n not 1 in the if statement
 * VID Section 6 part 2
 */
int fibonaicci (int n)
{
	if (n < 2) return n;
	else
	{
		return fibonaicci(n-1) +fibonaicci(n-2);
	}
}
int fib(int n)
{
    int x, y;
    if (n < 2) return n;
    if (n <= 30) return fibonaicci(n);
    else
    {
#pragma omp task shared(x)
        x = fib(n - 1);
#pragma omp task shared(y)
        y = fib(n - 2);
#pragma omp taskwait
    }
    return x + y;
}

int main()
{
    int n = 43;
    double start, end;
    start = omp_get_wtime();
#pragma omp parallel
        {
#pragma omp single
            {
                cout << "Fibonacci of " << n << " is " << fib(n) << endl;
            }
        }
    end = omp_get_wtime();
    //
    cout << "Time: " << end - start << endl;

    return 0;
}
