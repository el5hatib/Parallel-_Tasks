#include  <iostream>
#include <omp.h>
using namespace  std;
/*
 * Fibonacci function that computes the n Fibonacci number serial code
 * 
 */
int fibonacci(int n)
{
		int i, j;
if (n<2)
	return n;
else
{
	i = fibonacci(n-1);
	j = fibonacci(n-2);
	return i+j;
}
}
int main()
{

int n = 45;
	int result;
	double start, end;
	start = omp_get_wtime();
	result = fibonacci(n);
	end = omp_get_wtime();
	cout << "Fibonacci(" << n << ") = " << result << endl;
	cout << "Time: " << end - start << endl;
	return 0;

}
