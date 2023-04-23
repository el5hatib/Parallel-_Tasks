#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int id;
    double STime = omp_get_wtime(); 
#pragma omp parallel num_threads(2) private(id)
    {
        id = omp_get_thread_num();
#pragma omp for schedule(dynamic , 3)
        for (int i = 1; i <= 20; i++)
        {
            cout << "Hello World " << i << " from thread: " << id << "\n";
        }
    }
    double TakenTime = omp_get_wtime()-STime;
    cout << "Time : " << TakenTime << endl; 
    return 0;
}
