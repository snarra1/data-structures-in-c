#include "random.h"
#include <time.h>

void SeedRand()
{
  srand(time(NULL));
}

int getRand()
{
  return rand()%40;
}

int getRandBetween(int min,int max)
{  
  return rand() % (max - min) + min;
  
}    
