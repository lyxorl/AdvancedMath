#include "matrixHeader.h"

matrix constantMatrix(int n, int m, double d){
    //Fill the matrix with value d in each cases
    //Fill the matrix with 0

    matrix result = createMatrix(n,m);

    for(int x = 0; x< result.sizeX; x++){
        for(int y = 0; y< result.sizeY; y++){
            result.grid[y][x] = d;
        }
    }
    return result;
}

matrix nullMatrix(int n, int m){
    matrix result = constantMatrix(n, m, 0.0);
    return result;
}

matrix scalarMatrix(int n, double d){
    
    matrix result = nullMatrix(n,n);
    for(int x = 0; x<result.sizeX; x++){
        result.grid[x][x] = d;
    }
}

matrix identityMatrix(int n){
    matrix result = scalarMatrix(n, 1.0);
    return result;
}