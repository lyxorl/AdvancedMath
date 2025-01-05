#include "matrixHeader.h"


int determinant(matrix M){

    if(M.sizeX != M.sizeY){
        printf("Impossible to calculate determinant that not a square matrix : %dx%d",M.sizeY,M.sizeX);
        exit(1);
    }

    return 0;//TO DO
}

void printMatrix(matrix M){
    // add parametter to format print with float

    printf("|");
    for (int x = 0; x<M.sizeX; x++){
        for (int y = 0; y<M.sizeY; y++){
            printf("%f ",M.grid[y][x]);
        }
        printf("|\n");
        if(x < M.sizeX-1){printf("|");}
    }
}

int main(){

    return 0;
}