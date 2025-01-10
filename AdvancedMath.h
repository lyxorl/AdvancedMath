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
} coefObj;

typedef struct {
    int x; //nbLine
    int y; //nbColomn
    coefObj **value;
}matrix;

typedef struct {
    int degree;
    coefObj *value;
}polynomial;

#endif