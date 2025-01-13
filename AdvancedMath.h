#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef matrixStruct
#define matrixStruct

typedef enum {
    FLOAT,
    MAT,
    POL,
    COMPLEX,
} ObjectType;

typedef struct{
    float real;
    float imaginary;
} complexNumber;

typedef struct {
    ObjectType type;
    void *value;
} Obj;

typedef struct {
    int x; //nbLine
    int y; //nbColomn
    ObjectType type; // type of coefficient : can be FLOAT COMPLEX or POLYNOMIAL
    // /!\ no test on type care can be add later
    Obj **value;
}matrix;

typedef struct {
    int degree;
    ObjectType type; // type of coefficient : can be FLOAT or COMPLEX
    // /!\ no test on type care can be add later
    Obj *value;
}polynomial;

#endif

//objetConvert.c
Obj floatToObj(float d);
float objToFloat(Obj o);

//objetOperator.c
Obj sum(Obj A, Obj B);

//complex.c
complexNumber sumComplexNumber(complexNumber a, complexNumber b);
complexNumber productComplexNumber(complexNumber a, complexNumber b);
complexNumber conjugateComplexNumber(complexNumber a);
Obj modulusComplexNumber(complexNumber a);

//matrix.c
matrix createMatrix(int x, int y);
matrix sumMatrix(matrix A, matrix B);
matrix productMatrix(matrix A, matrix B); //not done

//polynomial.c
polynomial createPolynom(int d);
polynomial sumPolynomial(polynomial A, polynomial B);
polynomial productPolynomial(polynomial A, polynomial B); //not done

//add free memory function for each type in particualry for Obj