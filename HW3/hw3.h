#ifndef HW3_H_
#define HW3_H_

	//Creates a structure named geoData

struct geoData{
	int maxTerms;	 //holds max no. of terms
	float errorTol; 	//stores error tolerance
	float x; 	//holds the input value 'x'
};

	//createGeoData function declaration

struct geoData createGeoData(int max, float error, float x);

	//calculateGeo function declaration

struct geoData calculateGeo(struct geoData gd);

	//printGeoData function declaration

void printGeoData(struct geoData gd);

	//calculateGeoSeries function declaration

void calculateGeoSeries(struct geoData gd[],int arraySize);

#endif
