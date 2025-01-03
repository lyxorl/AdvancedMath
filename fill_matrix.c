#include "matrixHeader.h"

void zeroMatrix(matrix M){
    //Fill the matrix with 0
    for(int x = 0; x< M.sizeX; x++){
        for(int y = 0; y< M.sizeY; y++){
            M.grid[y][x] = 0.0;
        }
    }
}
