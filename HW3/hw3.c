#include "hw3.h" //includes user-defined header file

#include <stdio.h> //includes standard input-output library

	//createGeoData function definition

struct geoData createGeoData(int max, float error, float x)
{
	struct geoData gd; //creates a structure gd of type geoData

		//sets the values of the structure to the input values
	gd.maxTerms=max;
	gd.errorTol=error;
	gd.x=x;

	return gd; //returns the initialized structure
}

	//calculateGeo function definition

struct geoData calculateGeo(struct geoData gd)
{
	struct geoData gdtemp; 		//temporary structure stores calculated
	float sum=0; 		//holds temporary sum of series till 'i' terms
	float abserror; //holds absolute difference of expected value and current sum
	float xtemp; 		//holds temporary x value to calculate power
	float expected;
	int i;

	expected=1/(1+gd.x); //calculates expected sum of geometric series

	for(i=0;i<gd.maxTerms;i++)
	{
		if(i==0) //calculates for first term
		{
			xtemp=1;
			sum=1;
		}
		else if(i%2==0) //calculates for even power terms
		{
			xtemp=xtemp*gd.x;
			sum=sum+xtemp;
		}
		else if(i%2>0) //calculates for odd power terms
		{
			xtemp=xtemp*gd.x;
                        sum=sum-xtemp;
		}
		abserror=expected-sum; //calculates absolute error
		if(abserror<0)
		{
			abserror=sum-expected;
		}
		if(abserror<gd.errorTol) //selects term with minimum error tolerance
		{
			break;
		}
	}
			//setting last calculated values to new temporary structure
	gdtemp.maxTerms=i+1;
	gdtemp.errorTol=abserror;
	gdtemp.x=sum;
	return gdtemp; //returns geoData structure with new calculated values
}

	//printGeoData function definition

void printGeoData (struct geoData gd)
{
		//prints values of geoData structure
	printf("\n %d\t%0.6f\t%0.9f\n\n",gd.maxTerms,gd.x,gd.errorTol);
}

	//calculateGeoSeries function definition

void calculateGeoSeries(struct geoData gd[], int arraySize)
{
	int i;

	for(i=0;i<arraySize;i++) //calculates Geometric series for each geoData structure in the input array
	{
		gd[i]=calculateGeo(gd[i]); 	//calls calculateGeo function for each structure
		printGeoData(gd[i]); 	//printGeoData function called
	}
}
