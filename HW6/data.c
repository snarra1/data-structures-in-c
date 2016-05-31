#include "data.h"

	//createDataLetters function definition
struct data* createDataLetters(char* str)
{
	//allocates memory and assigns values to data structure
	struct data* dta = malloc(sizeof(struct data));
	dta->letters = malloc(strlen(str)+1 * sizeof(char));
	dta->letters = strcpy(dta->letters,str);
	dta->letters[strlen(str)]='\0';
	dta->v1 = 0;
	dta->v2 = 0;
	return dta;
}

	//defining prinData function
void printData(struct data *dta)
{
	//prints data in the data structure
  printf("%f %f %s\n",dta->v1,dta->v2,dta->letters);
}
