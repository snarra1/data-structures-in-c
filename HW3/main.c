#include "hw3.h" //includes user-defined 'hw3.h' file

	//main function definition
int main()
{
	int arraySize=1;
	struct geoData gd[arraySize]; 	//array of geoData structure

	gd[0]=createGeoData(50,0.0010,0.5); 	//createGeoData function is called
	calculateGeoSeries(gd,arraySize);   //calls calculateGeoSeries function

	return 0; //successful termination of main
}
