

typedef struct 
{
	int size;
	int dataSize;
	int* data;
} darray;


darray darrayCreate(int size);
void darrayReserve(darray* arr, int size);
void darrayResize(darray* arr, int size);
void darrayAppend(darray* arr, int value);
int* darrayAt(darray* arr, int index);
void darrayDestroy(darray* arr);
void darrayDebug(darray* arr);