#include "AdvancedMath.h"

Obj nullObject(ObjectType ObjT){
    // Optional arguments for subType in polynomial and matrix and size for matrix

    Obj result;
    result.type = ObjT;
    switch(result.type){
        case FLOAT:     result.value = malloc(sizeof(float));
                        *(float *)(result.value) = 0.;
                        break;
        case COMPLEX:   result.value = malloc(sizeof(complexNumber));
                        *(complexNumber*)(result.value) = nullComplexNumber();
                        break;
        case POL:       result.value = malloc(sizeof(polynomial));
                        *(polynomial *)(result.value) = nullPolynomial(FLOAT);//FLOAT DEFAULT VALUE
                        break;
        case MAT:       result.value = malloc(sizeof(matrix));
                        *(matrix *)(result.value) = nullMatrix(1,1,FLOAT); //FLOAT 1,1 DEFAULT VALUE
                        break;
        default:break;
    }

    return result;

}

Obj sum(Obj A, Obj B){
    
    if (A.type != B.type){
        printf("The two objects don't have the same type. Impossible to sum");
        exit(1);
    }

    Obj result;
    result.type = A.type;

    switch(result.type){
        case COMPLEX:   result.value = malloc(sizeof(complexNumber));
                        *(complexNumber *)(result.value) = sumComplexNumber(*(complexNumber *)(A.value), *(complexNumber *)(B.value));
                        break;
        case FLOAT:     result.value = malloc(sizeof(float));
                        *(float *)(result.value) = *(float *)(A.value) + *(float *)(B.value);
                        break;
        case POL:       result.value = malloc(sizeof(polynomial));
                        *(polynomial *)(result.value) = sumPolynomial(*(polynomial *)(A.value), *(polynomial *)(B.value));
                        break;
        case MAT:       result.value = malloc(sizeof(matrix));
                        *(matrix *)(result.value) = sumMatrix(*(matrix*)(A.value),*(matrix*)(B.value));
                        break;
        default: break;
    }
    
    return result;
}

Obj product(Obj A, Obj B){

    if (A.type != B.type){
        printf("The two object has not the same type. Impossible to product");
        exit(1);
    }

    Obj result;
    result.type = A.type;

    switch(result.type){
        case COMPLEX:   result.value = malloc(sizeof(complexNumber));
                        *(complexNumber *)(result.value) = productComplexNumber(*(complexNumber *)(A.value), *(complexNumber *)(B.value));
                        break;
        case FLOAT:     result.value = malloc(sizeof(float));
                        *(float *)(result.value) = (*(float *)(A.value))*(*(float *)(B.value));
                        break;
        case POL:       result.value = malloc(sizeof(matrix));
                        *(polynomial *)(result.value) = productPolynomial(*(polynomial *)(A.value), *(polynomial *)(B.value));
                        break;
        case MAT:       result.value = malloc(sizeof(matrix));
                        *(matrix *)(result.value) = productMatrix(*(matrix*)(A.value),*(matrix*)(B.value));
                        break;
        default: break;
    }

    return result;

}