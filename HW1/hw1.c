/*************************************************************
* Author : Supraja Narra
* Language : C
* Purpose : Program to create functions for adding and dividing
* no.s
**************************************************************/

#include <stdio.h> //Header File

	//addValues function definition
void addValues(int a,int b,int c)
{
	int res; // holds result of addition
	res=a+b+c; //adds arguments a,b & c
	printf("\n %d\n",res); //prints addition result
}

	//Defining divideValues function 
double divideValues(float val1,float val2,float val3)
{
	double res; // stores result of division
	res=val1/val2; // divides  argument1 by argument2
	res=res/val3; // divides 1st division result by argument3
	return res; // returns result to calling function
}
	// callfunc definition
void callfunc(float a, float b, float c)
{
	double res; //stores returned value
	res=divideValues(a,b,c); // call to divideValues function
	printf("\n %lf\n",res);// printing division result
}

	//main function definition
int main()
{
	addValues(2,4,6); //calls addValues function
	callfunc(36.0,3.0,2.0); //callfunc function is called
	return 0; //terminating main function
}
 //End of program
