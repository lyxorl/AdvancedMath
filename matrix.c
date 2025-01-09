#include "AdvancedMath.h"

matrix createMatrix(int x, int y){
    matrix result;

    result.x = x;
    result.y = y;

    result.value = malloc(sizeof(coefMat*)*y);
    for(int i = 0; i<y; i++){
        result.value[i] = malloc(sizeof(coefMat)*x);
    }

    return result;
}