#include <iostream>
#include <omp.h>
#include <cstdlib>
using namespace std; 
/*
Summation of two array serial
*/
int main()
{
	double a[10000], b[10000], c[10000];
	for (int i = 0; i < 10000; i++)
	{
		a[i] = rand();
		b[i] = rand();
	}
	float STime = omp_get_wtime();
	for (int x = 0; x < 10000; x++)
	{
		c[x]= a[x] + b[x] ;

	}
	float TakenTime = omp_get_wtime()-STime;
	cout << "The Time is =  " << TakenTime << "  Seconde" << endl; 
	return 0; 
}