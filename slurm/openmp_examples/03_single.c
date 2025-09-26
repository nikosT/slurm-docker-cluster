#include "omp.h"
#include <stdio.h>

int main()
{
  int num_threads = 1; // default value

  #pragma omp parallel
  {
      if (omp_get_thread_num() == 0) {
          num_threads = omp_get_num_threads();
      }
  }

  printf("We have %d threads.\n", num_threads);

  #pragma omp single
  {
    printf("Hi from thread:%d \n", omp_get_thread_num());
  }
}
