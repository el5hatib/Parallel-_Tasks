#include  <iostream>
#include  <cstdlib>
#include  <omp.h>
using namespace  std;
/*
 *               parallel multiplication of two matrices          *
 * N column of matrix A should be equal to N row of matrix B
 * The result of matrix multiplication is a matrix with N row of matrix A and N column of matrix B
 */
int main()
{
	int rowA =3, colA=2, rowB=2, colB=3;
	int arr_a[3][2];
	int arr_b[2][3];
	int arr_c[3][3];
#pragma  omp parallel for collapse(2)
	for (int i=0; i<rowA; i++)
	{
		for (int j=0; j<colA; j++)
		{
			arr_a[i][j] = rand();
		}
	}
#pragma omp parallel for collapse(2)
	for (int i=0; i<rowB; i++)
	{
		for (int j=0; j<colB; j++)
		{
			arr_b[i][j] = rand();
		}
	}
#pragma  omp parallel for
	for (int i = 0; i < rowA; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			arr_c[i][j] = 0;
			for (int k = 0; k < colA; k++)
			{
				arr_c[i][j] += arr_a[i][k] * arr_b[k][j];
			}
		}
	}
	cout << "Matrix Result" << endl;
	cout << "=============" << endl;
	for ( int i = 0; i < rowA; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			cout << arr_c[i][j] << " ";
		}
		cout << endl;
	}
	return 0; 
}