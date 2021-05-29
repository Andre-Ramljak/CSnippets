#include "darray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

darray darrayCreate(int size)
{
	printf("DArray: Creating dynamic array size: %d\n", size);

	darray arr;
	arr.data = malloc(sizeof(int) * size);
	arr.size = 0;
	arr.dataSize = size;
	return arr;
}


void darrayReserve(darray* arr, int size)
{
	printf("DArray: Reserving dynamic array from %d to %d\t", arr->dataSize, size);

	int* newData = malloc(sizeof(int) * size);

	printf("Memcpy\t");
	memcpy(newData, (*arr).data, (*arr).size);
	
	printf("Free\t");
	free(arr->data);
	arr->data = newData;
	arr->dataSize = size;

	printf("Complete\n");
}


void darrayResize(darray* arr, int size)
{
	//Check if size can be fit within data size
	if (size > arr->dataSize)
	{
		//Need to reserve more space
		darrayReserve(arr, size);
	}
	
	arr->size = size;
}


void darrayAppend(darray* arr, int value)
{
	if (arr->size >= arr->dataSize) /* Handle appending outside of data range*/
	{
		darrayResize(arr, (*arr).dataSize + 1);
	}
	
	arr->data[arr->size] = value;
	arr->size += 1;
}


int* darrayAt(darray* arr, int index)
{
	printf("DArray: Attempting to access value at %d\n", index);

	assert(index < arr->size);
	
	return &(arr->data)[index];
	
}


void darrayDestroy(darray* arr)
{
	printf("DArray: Destroying dynamic array\n");
	free(arr->data);
}

void darrayDebug(darray* arr)
{
	printf("DArray: debug\n");
	printf("DArray: Size %d, data size %d\n", (*arr).size, (*arr).dataSize);
	for (int i = 0; i < arr->dataSize; i++)
	{
		printf("DArray: %d: %d\n", i, arr->data[i]);
	}
}