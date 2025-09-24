#define _GNU_SOURCE  // Must be defined before any headers to get GNU extensions

#include <stdio.h>
#include <unistd.h>
#include <omp.h>
#include <sched.h>
#include <stdlib.h>

// compile gcc -fopenmp -O3 openmp_hello.c -o openmp_hello

int get_socket_id(int cpu_id) {
    char path[128];
    snprintf(path, sizeof(path),
             "/sys/devices/system/cpu/cpu%d/topology/physical_package_id", cpu_id);

    FILE *f = fopen(path, "r");
    if (!f) {
        return -1; // Failed to read socket ID
    }

    int socket_id;
    if (fscanf(f, "%d", &socket_id) != 1) {
        fclose(f);
        return -1;
    }
    fclose(f);
    return socket_id;
}

int main(int argc, char *argv[]) {
    char hostname[256];
    gethostname(hostname, sizeof(hostname));

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        int cpu_id = sched_getcpu();   // Now properly declared
        int socket_id = get_socket_id(cpu_id);

        printf("Hello from thread %d of %d on %s (pid: %d) | CPU: %d | Socket: %d\n",
               tid, num_threads, hostname, getpid(), cpu_id, socket_id);
    }

    return 0;
}

