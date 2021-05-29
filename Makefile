#Makefile comment section

CC=cc #Compiler
TARGET=main #target file name

all: main.o darray.o
	$(CC) main.c darray.c -o $(TARGET)

clean:
	rm *.o $(TARGET)

