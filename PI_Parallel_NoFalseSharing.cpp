#include <iostream>
#include <omp.h>
using namespace std;
/*
*  ## PI in Parallel No False Sharing ##
* Taked 6 sec
*/
int main() {
    int steps = 1000000000;
    double rate = 1.0 / steps;
    double sum[2][8];
    for (int i = 0; i < 2; i++)
    {
        sum[i][0] = 0;
    }
    float stime = omp_get_wtime();
#pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();
        for (int i = id; i < steps; i += nthreads) {
            double x = (i + 0.5) * rate;
            sum[id][0] += 4.0 / (1.0 + x * x);
        }
    }

    double pi = 0;
    for (int i = 0; i < 2; i++) {
        pi += sum[i][0] * rate;
    }
    float etime = omp_get_wtime();
    float takentime = etime - stime;
    cout << "The Value Of PI =  " << pi << endl;
    cout << "Taken Time = " << takentime << endl;
    return 0;
}