#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

// compile gcc -fopenmp -O3 montecarlo.c -o montecarlo

int main() {
    long num_points = 1000000000; // Fixed problem size
    long points_inside_circle = 0;
    double start_total, end_total, start_thread, end_thread;

    // Seed the random number generator with thread-safe seeding
    srand(time(NULL));

    // Start total time measurement
    start_total = omp_get_wtime();

    #pragma omp parallel reduction(+:points_inside_circle)
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        long points_per_thread = num_points / num_threads;
        long local_count = 0;

        // Ensure thread-safe random number generation
        unsigned int seed = time(NULL) + thread_id;

        // Start per-thread time measurement
        start_thread = omp_get_wtime();

        // Generate random points for this thread
        for (long i = 0; i < points_per_thread; i++) {
            double x = (double)rand_r(&seed) / RAND_MAX * 2.0 - 1.0; // [-1, 1]
            double y = (double)rand_r(&seed) / RAND_MAX * 2.0 - 1.0; // [-1, 1]
            if (x * x + y * y <= 1.0) {
                local_count++;
            }
        }

        // End per-thread time measurement
        end_thread = omp_get_wtime();
        points_inside_circle += local_count;

        // Print per-thread time
        printf("Thread %d: Time = %.6f seconds\n", thread_id, end_thread - start_thread);
    }

    // End total time measurement
    end_total = omp_get_wtime();

    // Calculate pi
    double pi_estimate = 4.0 * points_inside_circle / num_points;

    // Print results
    printf("\nEstimated value of π: %.6f\n", pi_estimate);
    printf("Total execution time: %.6f seconds\n", end_total - start_total);
    printf("Number of threads used: %d\n", omp_get_max_threads());

    return 0;
}
