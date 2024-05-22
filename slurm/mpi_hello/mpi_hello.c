#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    // Initialize MPI environment
    MPI_Init(&argc, &argv);

    // Get the rank and size of the MPI communicator
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Get the hostname of the current node
    char hostname[256];
    gethostname(hostname, sizeof(hostname));

    // Print the hostname and process ID
    printf("Hello from rank %d of %d on %s (pid: %d)\n", rank, size, hostname, getpid());

    // Finalize MPI environment
    MPI_Finalize();

    return 0;
}

