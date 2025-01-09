#include "AdvancedMath.h"

polynom createPolynom(int d){
    polynom result;
    result.degree = d;

    result.value = malloc((d+1)*sizeof(coefObj));

    return result;
}