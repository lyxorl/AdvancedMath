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

matrix sumMatrix(matrix A, matrix B){

    if (A.x != B.x || A.y != B.y){
        printf("Error impossible to sum matrix the size are not the same");
        exit(1);
    }

    //To do
    //make double for loop and sum coefficient with coefficient

    matrix result;
    return result;

}