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

matrix removeLine(matrix M, int n){

    // Add verification for n beteween 0 and M.sizeX-1

    matrix result = createMatrix(M.sizeX - 1, M.sizeY);
    int selectedX = 0;

    for (int x = 0; x<M.sizeX; x++){
        if (x == n){
            selectedX++;
        }
        else{
            for (int y = 0; y<M.sizeY; y++){
                result.grid[y][x] = M.grid[y][selectedX];
            }
        }
        selectedX++;
    }

    return result;
}

matrix removeColomn(matrix M, int n){

    // Add verification for n between 0 and M.sizeY-1
    
    matrix result = createMatrix(M.sizeX, M.sizeY - 1);
    int selectedY = 0;

    for (int x = 0; x<M.sizeX; x++){
        for (int y = 0; y<M.sizeY-1; y++){
            if (y == n){
                selectedY++;
            }
            result.grid[y][x] = M.grid[selectedY][x];
            selectedY++;
        }
    }

    return result;
}

int determinant(matrix M){

    if(M.sizeX != M.sizeY){
        printf("Impossible to calculate determinant that not a square matrix : %dx%d",M.sizeY,M.sizeX);
        exit(1);
    }

    if (M.sizeX == 1){
        return M.grid[0][0];
    }
    else{
        int det = 0;
        for (int x = 0; x < M.sizeX;x++)
            det = det+M.grid[0][x]*determinant(removeColomn(removeLine(M,x),0));
        return det;
    }
}