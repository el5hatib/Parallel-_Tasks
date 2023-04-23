#include <iostream>
#include <omp.h>
using namespace std;
/*
Calculate Value of PI using reduction
*/
int main()
{
	int steps = 10000;
	float rate = 1.0 / steps;
	float x;
	float sum = 0;
	float stime = omp_get_wtime();
#pragma omp parallel num_threads(2) private (x)
	{
#pragma omp for reduction(+:sum)
		for (int i = 0; i < steps; i++)
		{
			x = (i + 0.5) * rate;
			sum = sum + (4 / (1 + x * x));

		}

	}

	float pi = sum / steps;
	float etime = omp_get_wtime();
	float takentime = etime - stime;
	cout << "The Value Of PI =  " << pi << endl;
	cout << "Taken Time = " << takentime << endl;
	return 0;
}