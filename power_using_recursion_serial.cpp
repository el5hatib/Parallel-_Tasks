#include <iostream>
#include <omp.h>
using namespace	 std;
/*
                  * Power using recursion Serial*
 */
int power(int b, int e)
{
		if (e == 0)return 1;
		if (e == 1)return b;
		if (e ==2)return b * b;
	else
		return b * power(b, e - 1);
}
int main()
{
	double start, end;
	start = omp_get_wtime();
	cout << power(2, 10) << endl;
	end = omp_get_wtime();
	cout << "Time taken: " << end - start << endl;

	return 0;
}