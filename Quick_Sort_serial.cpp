#include <iostream>
#include <omp.h>
using namespace std;
/*
* Quick Sort Algorithm 
*/

void swap(int* a, int* b)
{
	int temp = *a; 
	*a = *b; 
	*b = temp; 
}
int partitioning(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}

	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}
void  quicksort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partitioning(arr, low, high); 
		quicksort(arr, low, pi - 1); 
		quicksort(arr, pi + 1, high); 
	}
}
void printarray(int arr[], int n)
{
	cout << "[ "; 
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]\n";
}
int main()
{
	int arr[] = { 10,5,4,8,6,7,8,9,1,0,2,3 };
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Unsorted Array \n";
	printarray(arr, n);
	quicksort(arr, 0, n-1);
	cout << "Sorted Array \n"; 
	printarray(arr, n);
	
	return 0; 
}