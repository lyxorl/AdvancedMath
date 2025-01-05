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