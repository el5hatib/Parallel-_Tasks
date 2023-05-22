/*
*binary search 
* note : binary search working on sorted array 
* so first we will write a sorting algorithm for exampl Quick sort algorithm 
* then call function of sorting to function of searching 
* lets's go
*/
#include <iostream>
#include <omp.h>
using namespace std; 
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
void SortArray(int arr[], int low, int high)
{
	if (low < high)
	{
		int nextPinot = partitioning(arr, low, high);
		SortArray(arr, low, nextPinot - 1);
		SortArray(arr, nextPinot + 1, high);
	}
}
int binarySearch(int arr[], int low, int high, int target) {
	if (high >= low) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == target)
			return mid;

		if (arr[mid] > target)
			return binarySearch(arr, low, mid - 1, target);

		return binarySearch(arr, mid + 1, high, target);
	}
	return -1;
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9, 11, 13 };
	int target = 22;
	int n = sizeof(arr) / sizeof(arr[0]);

	SortArray(arr, 0, n - 1);
	int index = binarySearch(arr, 0, n - 1, target);

	if (index != -1) {
		cout << "Target found at index " << index << endl;
	}
	else {
		cout << "Target not found" << endl;
	}

	return 0;
}