#include "AdvancedMath.h"

polynomial createPolynom(int d){

    polynomial result;
    result.degree = d;
    result.type = FLOAT;
    result.value = malloc((d+1)*sizeof(Obj));

    return result;
}

polynomial sumPolynomial(polynomial A, polynomial B){

    if (A.type != B.type){
        printf("Error : coeffient between A and B are different");
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