/*
  find the sum = 1-3^3+5^3-7^3+...+(-1)^n(2n+1),n=333
*/
#include <iostream>
#include <omp.h> 
#include <cmath>
using namespace std; 
/*int main() {
    int n = 333;
    int sum = 0;

    for (int i = 0; i <= n; i++) {
        int term = pow(-1, i) * pow(2 * i + 1, 3);
        sum += term;
    }

    cout << "Sum: " << sum << endl;

    return 0;
}
*/
int main() {
    int n = 333;
	int sum = 0;
	#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i <= n; i++) {
		int term = pow(-1, i) * pow(2 * i + 1, 3);
		sum += term;
	}
	cout << "Sum: " << sum << endl;
	return 0;
}