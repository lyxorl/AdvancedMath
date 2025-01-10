#include "AdvancedMath.h"

polynomial createPolynom(int d){
    polynomial result;
    result.degree = d;

    result.value = malloc((d+1)*sizeof(coefObj));

    return result;
}