#include "timing.h"



clock_t getTime()
{
  return clock();
}
float timeDiff(clock_t start,clock_t end)
{
  return (float)(end - start) / CLOCKS_PER_SEC;
}
