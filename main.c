#include "AdvancedMath.h"


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