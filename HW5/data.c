#include "data.h"

struct data* createData(float v1,float v2)
{
  struct data* dta = malloc(sizeof(struct data));
  dta->v1 = v1;
  dta->v2 = v2;
  return dta;
}


int compareData(struct data *dta1,struct data *dta2)
{
  if( (dta1->v1 == dta2->v1) && (dta1->v2 == dta2->v2))return 1;
  return 0;
}


float sumData(struct data *dta)
{
  return (dta->v1 + dta->v2);
}

void printData(struct data *dta)
{
  printf("%f %f\n",dta->v1,dta->v2);
}
