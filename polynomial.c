#include "AdvancedMath.h"

polynomial createPolynom(int d){

    polynomial result;
    result.degree = d;
    result.type = FLOAT;
    result.value = malloc((d+1)*sizeof(coefObj));

    return result;
}

polynomial sumPolynomial(polynomial A, polynomial B){

    if (A.type != B.type){
        printf("Error : coeffient between A and B are different");
        exit(1);
    }

    polynomial result;
    if (A.degree >= B.degree){
        result.degree = A.degree;
    }else{
        result.degree = B.degree;
    }
    result.type = A.type

    //define sum for Obj and create a for loop until the min degree and finih with set the other coefficient

    return result;

}