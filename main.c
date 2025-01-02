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

int determinant(matrix M){

    if(M.sizeX != M.sizeY){
        print("Impossible to calculate determinant that not a square matrix : %dx%d",M.sizeY,M.sizeX);
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