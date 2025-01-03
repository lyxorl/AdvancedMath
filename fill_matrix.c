#include "matrixHeader.h"

void constantMatrix(matrix M, double d){
    //Fill the matrix with value d in each cases
    //Fill the matrix with 0
    for(int x = 0; x< M.sizeX; x++){
        for(int y = 0; y< M.sizeY; y++){
            M.grid[y][x] = d;
        }
    }
}

void nullMatrix(matrix M){
    constantMatrix(M, 0.0);
}

void scalarMatrix(matrix M, double d){
    //only on square matrix
    if (M.sizeX != M.sizeY){
        printf("Not a square matrix");
        exit(1);
    }
    nullMatrix(M);
    for(int x = 0; x<M.sizeX; x++){
        M.grid[x][x] = d;
    }
}

void identityMatrix(matrix M){
    scalarMatrix(M, 1.0);
}