#include <stdio.h>
#include <stdlib.h>
#include "darray.h"


int main()
{
	printf("Hello world\n");
	
	darray arr = darrayCreate(5);
	/*darrayResize(&arr, 8); 
	printf("Potato");
	*/

	darrayReserve(&arr, 10);

	darrayAppend(&arr, 10);

	darrayDebug(&arr);

	*(darrayAt(&arr, 0)) = 5;

	darrayResize(&arr, 5);

	*(darrayAt(&arr, 2)) = 25;

	darrayDebug(&arr);

	darrayDestroy(&arr);
	
	return 0;
}

int foo(int a, int b)
{
	return a + b;
}
