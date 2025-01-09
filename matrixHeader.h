#include <stdio.h>
#include <stdlib.h>

#ifndef matrixStruct
#define matrixStruct

typedef struct {
    double** coefficient;
    int sizeX; //nbLine
    int sizeY; //nbColomn
}matrix;

#endif

matrix createMatrix(int n,int m);

//fill_matrix.c
matrix constantMatrix(int n, int m, double d);
matrix nullMatrix(int n, int m);
matrix scalarMatrix(int n, double d);
matrix identityMatrix(int n);

//classical_operator_matrix.c
matrix product(matrix A, matrix B);
matrix sum(matrix A, matrix B);

//matrix_operator.c
matrix transpose(matrix M);