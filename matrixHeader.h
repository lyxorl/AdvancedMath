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