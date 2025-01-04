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
    
    /*---test---*/
    /*
    //Test error with matrix creation - OK
    // matrix matrixError = createMatrix(-1,5);
    */
    
    /*
    //Test fill 0 in matrix and transpose - OK
    matrix matrixTest = createMatrix(5,7);
    nullMatrix(matrixTest);
    matrixTest.grid[2][3] = 2.3;
    matrix matrixTestTranspose = transpose(matrixTest);

    printMatrix(matrixTest);
    printf("\n");
    printMatrix(matrixTestTranspose);
    */

    /*
    //need to create a lot of test
    //Test product
    matrix matrixTestProductA = createMatrix(2,3);
    matrixTestProductA.grid[0][0] = 2.3;
    matrixTestProductA.grid[0][1] = 7.8;
    matrixTestProductA.grid[1][0] = 2.3;
    matrixTestProductA.grid[2][0] = 9.0;
    matrixTestProductA.grid[1][1] = 5.5;
    matrixTestProductA.grid[2][1] = 1.2;

    matrix matrixTestProductB = createMatrix(3,4);
    matrixTestProductB.grid[0][0] = 1.0;
    matrixTestProductB.grid[0][1] = 2.0;
    matrixTestProductB.grid[0][2] = 3.0;
    matrixTestProductB.grid[1][0] = 1.0;
    matrixTestProductB.grid[1][1] = 1.0;
    matrixTestProductB.grid[1][2] = 1.0;
    matrixTestProductB.grid[2][0] = 1.0;
    matrixTestProductB.grid[2][1] = 1.0;
    matrixTestProductB.grid[2][2] = 1.0;
    matrixTestProductB.grid[3][0] = 1.0;
    matrixTestProductB.grid[3][1] = 1.0;
    matrixTestProductB.grid[3][2] = 1.0;

    matrix matrixTestResultProduct = product(matrixTestProductA,matrixTestProductB);
    printMatrix(matrixTestProductA);
    printf("\n");
    printMatrix(matrixTestProductB);
    printf("\n");
    printMatrix(matrixTestResultProduct);
    */
    
    printf("-fin-\n");
    return 0;
}