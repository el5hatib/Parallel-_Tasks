#include <iostream>
#include <omp.h>
using namespace  std;
/*
				* Factorial using recursion Prallel Task *
 */
int factorial_prallel(int n)
{
	int x;
	int y;
	if (n == 0) return 1;

	else {
#pragma omp task shared(x,n)
		x = factorial_prallel(n - 1);
#pragma  omp taskwait
		return n*x; // return n * factorial(n - 1);

	}

}
int main()
{
	double start_time, end_time;
	start_time = omp_get_wtime();
	cout << "Enter a number: ";
	int n;
	cin >> n;
#pragma  omp parallel num_threads(4)
	{
		#pragma omp single
		{
			cout << "Factorial of " << n << " is " << factorial_prallel(n) << endl;
		}
	}
	end_time = omp_get_wtime();
	
	double time = end_time - start_time;
	cout << "Time taken: " << time << " seconds" << endl;

}