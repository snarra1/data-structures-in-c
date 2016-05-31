#include "random.h"


void randSeed()
{
  srand(time(NULL));
}
float genNumber()
{
  int ran = (rand() % 50000)-25000;
  return ran/100.00;
}
struct data* randomData()
{
  float val1 = genNumber();
  float val2 = genNumber();
  struct data* dta = createData(val1,val2);
  return dta;

}
