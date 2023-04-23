#include <iostream> 
#include <omp.h>
using namespace std; 
int main()
{
    const int n=5 ;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the array elements of  " << i+1 << ": " << endl;
        cin >> arr[i];
    }

    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= arr[i];
    }
    cout << "The product of the array elements is: " << product << endl;
	return 0; 
}