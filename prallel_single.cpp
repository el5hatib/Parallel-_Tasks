#include <iostream>
#include <omp.h>
using namespace  std; 
int main() {
    
    

#pragma omp parallel  num_threads(4)
    {   int num_threads = 0;
        int thread_id = 0;
        // Get the number of threads
#pragma omp single
        {
            num_threads = omp_get_num_threads();
           cout << "Number of threads: " << num_threads << endl;
        }

        // Each thread prints its ID
        thread_id = omp_get_thread_num();
       cout << " Hello from thread`  : " << thread_id << endl;
      
    }

    return 0;
}
