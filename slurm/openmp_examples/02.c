#include "omp.h"
#include <stdio.h>

#define NUM_TIMES 8

int main()
{
  int value = 0;

  #pragma omp parallel for
  for (int i = 0; i < NUM_TIMES; ++i)
  {
    value += 1;
  }

  printf("Result:%d \n", value);
}
