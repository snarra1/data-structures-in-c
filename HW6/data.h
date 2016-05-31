#ifndef DATA_H_
#define DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	//structure declaration
struct data
{
	float v1;
	float v2;
	char *letters;
};

	//function declarations
struct data* createDataLetters(char *str);
void printData(struct data *dta);

#endif
