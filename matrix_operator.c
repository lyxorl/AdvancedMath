#include "matrixHeader.h"

matrix transpose(matrix M){ 
    //No tested and add verification to see if the matrix contain value
    matrix result = createMatrix(M.sizeY,M.sizeX);
    for (int x = 0; x<M.sizeX; x++){
        for (int y = 0; y<M.sizeY; y++){
            result.grid[x][y] = M.grid[y][x];
        }
    }
    return result;
}

matrix removeColomn(matrix M){
    matrix result = createMatrix(M.sizeX - 1, M.sizeY);
    //TO DO
    return result;
}

matrix removeLine(matrix M){
    matrix result = createMatrix(M.sizeX, M.sizeY - 1);
    //TO DO
    return result;
}

int determinant(matrix M){

    if(M.sizeX != M.sizeY){
        printf("Impossible to calculate determinant that not a square matrix : %dx%d",M.sizeY,M.sizeX);
        exit(1);
    }

    //TO DO

    return 0;
}