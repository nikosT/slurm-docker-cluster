#include "omp.h"
#include <stdio.h>

int main()
{
  #pragma omp parallel
  {
    printf("Hello from process: %d \n", omp_get_thread_num());
  }
}
