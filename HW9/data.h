#ifndef DATA_H_
#define DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

struct data* createData(float v1,float v2);
int compareData(struct data *dta1,struct data *dta2);
float sumData(struct data *dta);
void printData(struct data *dta);
#endif
