#include  <iostream>
#include <omp.h>
using namespace  std;
/*
 * Binomial Coefficient Parallel code using recursion
 * There is a wrong way to calculate binomial coefficient  in Vid Section 6 part 3 in if condition
 * if (k == 0 || k == 0) return 1;   is wrong
 * the right way is if (k == 0 || k == n) return 1;
 */
int binomial_coefficient_serial(int n, int k)
{
	int x, y;

	if (k == 0 || k == n)
		return 1;
	else
	{
		x = binomial_coefficient_serial(n - 1, k - 1);
		y = binomial_coefficient_serial(n - 1, k);
		return x + y;
	}
	}

int binomial_coefficient_prallel(int n, int k)
{
	int x ,y ;
	if (n == 0) return 0;
	if (k == 0 || k == n) return 1;
	if (k>n) return 0; // k must be less than n or equal to n 
	if (n < 20 && k < 10) return  binomial_coefficient_serial(n, k);
	else
	{
#pragma omp  task shared(x)
		x = binomial_coefficient_prallel(n - 1, k - 1);
#pragma omp  task shared(y)
		y= binomial_coefficient_prallel(n - 1, k);
#pragma omp  taskwait
		return x + y;
	}
		
}
int main()
{
	double start_time, end_time;
	start_time = omp_get_wtime();
	end_time = omp_get_wtime();
#pragma  omp parallel
	{
		#pragma  omp single
		{
			cout << "binomial_coefficient(20, 10) = " << binomial_coefficient_prallel(20, 10) << endl;
		}
	}
	double time = end_time - start_time;
	cout << "time = " << time << endl;
	return 0;
}