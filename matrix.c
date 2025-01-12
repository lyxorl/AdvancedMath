#include "AdvancedMath.h"

matrix createMatrix(int x, int y){
    
    matrix result;
    result.x = x;
    result.y = y;
    result.type = FLOAT;
    result.value = malloc(sizeof(Obj*)*y);
    for(int i = 0; i<y; i++){
        result.value[i] = malloc(sizeof(Obj)*x);
    }

    return result;
}