#include <iostream>
#include <omp.h>
using namespace std;
int main()
{
    int steps = 10000000000;
    double rate = 1.0 / steps;
    double pi = 0.0;
    double sum[3] = { 0,0,0 };
    float stime = omp_get_wtime();
#pragma omp parallel num_threads(3)
    {
        int id = omp_get_thread_num();
        int threadsn = omp_get_num_threads();
        for (int i = id; i < steps; i += threadsn)
        {
            float x = ((i + 0.5) * rate);
            sum[id] += (4.0 / (1.0 + x * x));
        }
    }
    for (int i = 0; i < 3; i++)
    {
        pi = pi + sum[i] * rate;
    }
    float etime = omp_get_wtime();
    float takentime = etime - stime;
    cout << "The  Value Of PI = " << pi << endl;
    cout << "Taken Time =  " << takentime << endl;
    return 0;
}
