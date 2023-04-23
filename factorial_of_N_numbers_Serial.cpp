#include <iostream> 
#include <omp.h>
using namespace std;
int main()
{

	long n;
	cout << "please enter N numbers to calculate factorial for it : " << endl;
	cin >> n;
	long fact = 1;
	double STime = omp_get_wtime();
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}
	double ETime = omp_get_wtime();
	double TakenTime = ETime - STime;
	cout << "The result is =  " << fact << endl;
	cout << "Taken Time :  =  " << TakenTime << endl;
	return 0;
}
