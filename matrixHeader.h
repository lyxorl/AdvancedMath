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

matrix createMatrix(int n,int m);

//fill_matrix.c
void constantMatrix(matrix M, double d); // rewrite function with return matrix
void zeroMatrix(matrix M);
void scalarMatrix(matrix M, double d);
void identityMatrix(matrix M);

//operator_matrix.c
matrix product(matrix A, matrix B);
matrix sum(matrix A, matrix B);