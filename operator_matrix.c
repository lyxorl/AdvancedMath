#include "matrixHeader.h"

matrix sum(matrix A, matrix B){

    if(A.sizeX != B.sizeX || A.sizeY != B.sizeY){
        printf("Impossible to sum this matrix size is different :"); //Add format to align int in print of size
        printf("Size of the first  matrix : %dx%d",A.sizeY,A.sizeX);
        printf("Size of the second matrix : %dx%d",B.sizeY,B.sizeX);
        exit(1);
    } 

    matrix result = createMatrix(A.sizeX,A.sizeY);
    for(int x = 0; x < A.sizeX; x++){
        for(int y = 0; y <A.sizeY; y++){
            result.grid[y][x] = A.grid[y][x]+B.grid[y][x];
        }
    }
    return result;
}

matrix product(matrix A, matrix B){
    
    if(A.sizeY != B.sizeX){
        printf("Impossible to product this matrix");
        exit(1);
    }

    matrix result = createMatrix(A.sizeX,B.sizeY);
    for(int x = 0; x < A.sizeX; x++){
        for(int y = 0; y<B.sizeY; y++){

            float tmp = 0.0;
            for (int k = 0; k < A.sizeY; k++){
                tmp = tmp+A.grid[k][x]*B.grid[y][k];
            }
            result.grid[y][x] = tmp;
        } 
    }

    return result;
}