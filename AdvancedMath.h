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
    int x; //nbLine
    int y; //nbColomn
    coefMat **value;
}matrix;

typedef struct {
    int degree;
    coefPol *value;
}polynom;

#endif