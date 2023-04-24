#include <iostream>
#include  <omp.h>
using namespace  std;
/*
 * x-y and a+b using parallel sections
 * 
 */
	int main()
	{
		int x = 10, y = 20, a = 30, b = 40;
#pragma  omp parallel
		{

#pragma omp sections
			{
				#pragma omp section
				{
					cout << "x-y =  " << x - y << endl;
				}
#pragma omp section
				{
					cout << "a+b =  " << a + b << endl;
				}
			}
		}

		return 0;
	}