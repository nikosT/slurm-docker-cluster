#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    // Get the hostname of the current node
    char hostname[256];
    gethostname(hostname, sizeof(hostname));

    // Set the number of threads (optional - can be set via OMP_NUM_THREADS env variable)
    // omp_set_num_threads(4);
    
    // Parallel region starts here
    #pragma omp parallel
    {
        // Get the thread ID and total number of threads
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        
        // Print the hostname and process ID
        // Note: All threads share the same process ID since they're in the same process
        printf("Hello from thread %d of %d on %s (pid: %d)\n", 
               tid, num_threads, hostname, getpid());
    }

    return 0;
}
