#include <iostream>
#include  <omp.h>
using namespace  std;
/*
               * Power using recursion parallel task  * 
 */
int power (int b, int e)
{
		if (e == 0) return 1;
		if (e == 1) return b;
		if (e == 2) return b * b; 
		else
		{
#pragma omp task shared(b,e)
			{
				cout << "Thread " << omp_get_thread_num() << " is computing " << b << "^" << e  << endl;
			}
#pragma  omp taskwait
			return b*power (b, e - 1);
		}

		
}
int main ()
{

	double start = omp_get_wtime();
#pragma  omp parallel num_threads(4)
	{
#pragma omp single
		{
			cout << power(2, 10) << endl;
		}
	}
	double end = omp_get_wtime();
	double time = end - start;
	cout << "Time taken: " << time << endl;
	return 0;
}