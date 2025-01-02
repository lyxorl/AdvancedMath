#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double** grid;
    int sizeX;
    int sizeY;
}matrix;

matrix createMatrix(int n,int m){ 

    if (n <= 0 || m <= 0){
        printf("Enter positive intger\n");
        exit(1);
    }

    matrix result;
    result.sizeX = n;
    result.sizeY = m;
    result.grid = malloc(sizeof(double)*m);
    for (int i = 0; i<m; i++){
        result.grid[i] = malloc(sizeof(double)*n);
    }

    return result;
}

void zeroMatrix(matrix M){
    //Fill the matrix with 0

    for(int x = 0; x< M.sizeX; x++){
        for(int y = 0; y< M.sizeY; y++){
            M.grid[y][x] = 0.0;
        }
    }
}

matrix transpose(matrix M){ //No tested and add verification to see if the matrix contain value
    matrix result = createMatrix(M.sizeY,M.sizeX);
    for (int x = 0; x<M.sizeX; x++){
        for (int y = 0; y<M.sizeY; y++){
            result.grid[x][y] = M.grid[y][x];
        }
    }
    return result;
}

void printMatrix(matrix M){
    // add parametter to format print with float
    for (int x = 0; x<M.sizeX; x++){
        for (int y = 0; y<M.sizeY; y++){
            printf("%f ",M.grid[y][x]);
        }
        printf("\n");
    }
}

int main(){
    
    /*---test---*/
    /*
    //Test error with matrix creation - OK
    matrix matrixError = createMatrix(-1,5);
    */
    
    /*
    //Test fill 0 in matrix and transpose - OK
    matrix matrixTest = createMatrix(5,7);
    zeroMatrix(matrixTest);
    matrixTest.grid[2][3] = 2.3;
    matrix matrixTestTranspose = transpose(matrixTest);

    printMatrix(matrixTest);
    printf("\n");
    printMatrix(matrixTestTranspose);
    */
    
    return 0;
}