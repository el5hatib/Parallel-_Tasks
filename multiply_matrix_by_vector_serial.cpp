#include <iostream>
#include <omp.h>
#include <cstdlib>
using namespace std; 
/*
Multiply Vector by matrix serial
*/
int main()
{

	int  arr[3][2]; 
	int vect[3]; 
	int result[3] = {0,0,0};

	// Initialize arr with random values
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 2; j++)
		{
			arr[i][j] = rand(); 
		}
	}
	// Initialize vect with random values
	for (int i = 0; i < 2; i++)
	{
		vect[i] = rand();
	}
	float Stime = omp_get_wtime(); 
	// Perform matrix-vector multiplication
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 2; j++)
		{
			result[i] = result[i] + arr[i][j] * vect[j];
		}
		
	
	}
	float TakenTime = omp_get_wtime()-Stime;
// Print the result
	for (int i = 0; i < 3; i++)
	{
		cout << result[i] << " " << endl;
	}
	cout << "Taken Time" << TakenTime << "  Secondes" << endl;
	return 0; 
}