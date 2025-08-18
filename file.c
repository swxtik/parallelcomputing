//write an omp program which launches a parallel region and it has each thread, print its id and team size
#include <stdio.h>
#include <omp.h>
int main(){
    int thread_id,team_size;
    omp_set_dynamic(0);
    omp_set_num_threads(4);
    #pragma omp parallel 
    {
        thread_id=omp_get_thread_num();
        team_size=omp_get_num_threads();
        printf("Thread id = %d , team size = %d\n",thread_id,team_size);
    }
    return 0;
}