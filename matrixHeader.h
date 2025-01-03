#include <stdio.h>
#include <stdlib.h>

#ifndef matrixStruct
#define matrixStruct

typedef struct {
    double** grid;
    int sizeX; //nbLine
    int sizeY; //nbColomn
}matrix;

#endif


//fill_matrix.c
void constantMatrix(matrix M, double d);
void zeroMatrix(matrix M);
void scalarMatrix(matrix M, double d);
void identityMatrix(matrix M);