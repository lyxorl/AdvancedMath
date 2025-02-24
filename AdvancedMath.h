#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#ifndef mathStruct
#define mathStruct

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

//printObject
void printMatrix(matrix M);

void printComplexNumber(complexNumber a, bool bracket,  int prec, int limit_char);
// a the complex number
// bracket :    true -> (a+ib)
//              false -> a+ib
//prec : precision of the float
//limit_char superior at 4 with length (a+ib) and indicate the size max of char will be print

void printPolynomial(polynomial p, char indeterminate, int order);

void printOject(Obj);


//object.c
Obj floatToObj(float d);
float objToFloat(Obj o);
Obj nullObject(ObjectType ObjT);
Obj sum(Obj A, Obj B);
Obj product(Obj A, Obj B);

//complex.c
complexNumber nullComplexNumber();
complexNumber sumComplexNumber(complexNumber a, complexNumber b);
complexNumber productComplexNumber(complexNumber a, complexNumber b);
complexNumber conjugateComplexNumber(complexNumber a);
Obj modulusComplexNumber(complexNumber a);

//matrix.c
matrix createMatrix(int x, int y);
matrix nullMatrix(int x, int y, ObjectType ObjT);
matrix sumMatrix(matrix A, matrix B);
matrix scalarMatrix(Obj lambda, matrix A);
matrix productMatrix(matrix A, matrix B);

//polynomial.c
polynomial createPolynom(int d);
polynomial nullPolynomial(ObjectType ObjT);
polynomial sumPolynomial(polynomial A, polynomial B);
polynomial scalarPolynomial(Obj lambda, polynomial P);
polynomial productPolynomial(polynomial A, polynomial B);

//add free memory function for each type in particualry for Obj