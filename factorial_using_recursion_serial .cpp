#include <iostream>
#include <omp.h>
using namespace  std;
/*
                * Factorial using recursion serial* 
 */
int factorial (int n)
{
		if (n == 0)
		return 1;
	else
		return n * factorial (n - 1);
}
int main ()
{
	double start_time, end_time;
	start_time = omp_get_wtime();
	end_time = omp_get_wtime();
	cout << "Enter a number: ";
	int n;
	cin >> n;
	cout << "Factorial of " << n << " is " << factorial (n) << endl;
	double time = end_time - start_time;
	cout << "Time taken: " << time << " seconds" << endl;

}