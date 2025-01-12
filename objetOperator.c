#include "AdvancedMath.h"

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
        default: break;
    }
    
    return result;
}