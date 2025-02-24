#include "AdvancedMath.h"

polynomial createPolynom(int d){

    polynomial result;
    result.degree = d;
    result.type = FLOAT; // default should have a param to select type
    result.value = malloc((d+1)*sizeof(Obj));

    return result;
}

polynomial nullPolynomial(ObjectType ObjT){

    if (ObjT != FLOAT || ObjT != COMPLEX){
        printf("Error, polynomial can't have coefficient of this type");
        exit(1);
    }

    polynomial result;
    result = createPolynom(0);
    result.type = ObjT;

    Obj nullValue;

    switch(result.type){
        case COMPLEX:   nullValue.type = COMPLEX;
                        nullValue.value = malloc(sizeof(complexNumber));
                        *(complexNumber *)(nullValue.value) = nullComplexNumber();
                        break;
        case FLOAT:     nullValue.type = FLOAT;
                        nullValue.value = malloc(sizeof(float));
                        *(float *)(nullValue.value) = 0;
                        break;
        default: break;
    }
    result.value[0] = nullValue;

    return result;
}

polynomial identityPolynomial(ObjectType ObjT){
    if (ObjT != FLOAT || ObjT != COMPLEX){
        printf("Error, polynomial can't have coefficient of this type");
        exit(1);
    }

    polynomial result;
    result = createPolynom(0);
    result.type = ObjT;

    Obj nullValue;

    switch(result.type){
        case COMPLEX:   nullValue.type = COMPLEX;
                        nullValue.value = malloc(sizeof(complexNumber));
                        *(complexNumber *)(nullValue.value) = identityComplexNumber();
                        break;
        case FLOAT:     nullValue.type = FLOAT;
                        nullValue.value = malloc(sizeof(float));
                        *(float *)(nullValue.value) = 1;
                        break;
        default: break;
    }
    result.value[0] = nullValue;

    return result;
}

polynomial sumPolynomial(polynomial A, polynomial B){

    if (A.type != B.type){
        printf("Error : coeffient between A and B are not summable");
        exit(1);
    }

    int max_degree = 0;
    int min_degree = 0;
    polynomial poly_max;

    if (A.degree >= B.degree){
        max_degree = A.degree;
        min_degree = B.degree;
        poly_max = A;
    }else{
        max_degree = B.degree;
        min_degree = A.degree;
        poly_max = B;
    }

    polynomial result;
    result = createPolynom(max_degree);
    result.type = A.type;

    for (int d = 0; d<= min_degree; d++){
        result.value[d] = sum(A.value[d], B.value[d]);
    }
    for (int d = min_degree+1; d<= max_degree; d++){
        result.value[d] = poly_max.value[d];
    }

    return result;

}

polynomial scalarPolynomial(Obj lambda, polynomial P){

    if (lambda.type == MAT || lambda.type == POL){
        printf("Error : non good type scalar");
        exit(1);
    }
    if (lambda.type != P.type){
        printf("Error : scalar has not the type as the coefficient of the polynomial");
        exit(1);
    }

    polynomial result;
    result.type = P.type;
    result.degree = P.degree;

    for (int d = 0; d<= P.degree; d++){
        result.value[d] = product(lambda, P.value[d]);
    }

    return result;

}

polynomial productPolynomial(polynomial A, polynomial B){

    if (A.type != B.type){
        printf("Error : coeffient between A and B are not productable");
        exit(1);
    }

    polynomial result;

    result.type = A.type;
    result.degree = A.degree+B.degree;

    for (int d = 0; d <= (A.degree+B.degree); d++){
        Obj nullCoef; // Create null Obj with type in argument in objetOperator.c
        nullCoef = nullObject(result.type);
        result.value[d] = nullCoef;
        for (int dA = 0; dA <= d; dA++){
            result.value[d] = sum(result.value[d], product(A.value[dA],B.value[d-dA]));
        }
    }

    return result;

}

Obj evaluate(polynomial P, Obj value){

    Obj result;
    result.type = value.type;

    return result;

}

void printPolynomial(polynomial p, char indeterminate, int order){

    // indetrminate 'X' or 'Y' or etc
    // if Y for example we have 5 + Y + Y^2 ...
    // order    1 = asc  -> 1   +  X +   X^2 .....
    //          0 = desc -> X^n + 2X^3 + X^2 + 5X + 4

    // Add limit of character to be print in matrix.
    // Add ...

    for (int d = 0; d<=p.degree; d++){
        switch(p.type){
            case FLOAT:
                printf("%f", *(float *)(p.value[d].value));
                break;
            case COMPLEX:
                printComplexNumber(*(complexNumber *)(p.value[d].value),true,6,1);
            default:break;
            if (d!=0){
                
                //if possible set power in unicode with real power
                //need to check the terminal to know if that possible

                printf("%c%d",indeterminate,d);
            }
        }

        printf(" + ");
    }
    
    
}