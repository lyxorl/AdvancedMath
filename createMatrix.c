#include "matrixHeader.h"

matrix createMatrix(int n,int m){ 

    if (n <= 0 || m <= 0){
        printf("Enter positive intger\n");
        exit(1);
    }

    matrix result;
    result.sizeX = n;
    result.sizeY = m;
    result.grid = malloc(sizeof(double)*m); //construction of matrix witch colomn vectors
    for (int i = 0; i<m; i++){
        result.grid[i] = malloc(sizeof(double)*n);
    }

    return result;
}