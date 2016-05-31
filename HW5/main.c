		//includes libraries
#include "vector.h"
#include "data.h"

		//main function definition
int main()
{
	int i;
	float addn=0;
	struct vector* vec = createVector();
	struct vector* vec1 = NULL;
	struct vector* vec2 = createVector();

		//addFront and addBack function called
	addFront(vec, createData(1.0,1.0));
	addFront(vec, createData(2.0,2.0));
	addFront(vec, createData(3.0,3.0));
	addFront(vec, createData(4.0,4.0));
	addFront(vec, createData(5.0,5.0));
	addBack(vec, createData(0.0,0.0));

	addFront(vec2, createData(2.0,2.0));
	addBack(vec2, createData(1.0,1.0));

		//calls printVector
	printf("\n Vectors \n");
	printVector(vec);
	printVector(vec2);

	addn=sumVector(vec);
	printf("\n %f\n",addn);

		//calling removeBack and removeFront function
	removeBack(vec);
	removeFront(vec);
	printf("\n After Removing \n");
	printVector(vec);

	addn=sumVector(vec);
	printf("\n %f\n",addn);

		//calls cloneVector function
	vec1=cloneVector(vec);
	printf("\n Clone Vector \n");
	printVector(vec1);

		//compareVectors function called
	i=compareVectors(vec, vec1);
	printf("\n %d\n",i);

	i=compareVectors(vec, vec2);
	printf("\n %d\n",i);

	printf("\n Reverse Vector \n");
	reverseVector(vec);
	printVector(vec);

		//called cleanVector function
	cleanVector(vec);
	printf("\n After Cleaning Original, Clone is : \n");
	printVector(vec1);
	cleanVector(vec1);
	cleanVector(vec2);
	return 0;	//termination of main function
}
