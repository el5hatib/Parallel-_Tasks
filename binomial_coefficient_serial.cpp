#include  <iostream>
#include <omp.h>
using namespace  std;
/*
 * Binomial Coefficient Serial Code using recursion
 * There is a wrong way to calculate binomial coefficient  in Vid Section 6 part 3 in if condition
 * if (k == 0 || k == 0) return 1;   is wrong
 * the right way is if (k == 0 || k == n) return 1;
 */

int binomial_coefficient(int n, int k)
{
		if (k == 0 || k == n)
		return 1;
	else
		return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
}
int main ()
{
	double start_time = omp_get_wtime();
	cout << "Binomial Coefficient of 8 and 5 is " << binomial_coefficient(8, 5) << endl;
	double time = omp_get_wtime() - start_time;
	cout << "Time taken is " << time << endl;

	return 0;
}