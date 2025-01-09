#include <stdio.h>
#include <stdlib.h>

#ifndef matrixStruct
#define matrixStruct

typedef enum {
    COEF_FLOAT,
    COEF_MAT,
    COEF_POL
} Object;

typedef struct {
    Object type;
    void *value;
} coefMat;

typedef struct {
    Object type;
    void *value;
} coefPol;

typedef struct {
    int sizeX; //nbLine
    int sizeY; //nbColomn
    coefMat **value;
}matrix;

typedef struct {
    int degrees;
    coefPol *value;
}

#endif