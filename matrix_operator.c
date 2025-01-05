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