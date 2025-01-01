#include <stdio.h>
#include <stdlib.h>

struct {
    double** matrix;
    int sizeX;
    int sizeY;
}typedef matrix;

matrix* createMatrix(int n,int m){ //No tested and add verification for n and m
    matrix* result = malloc(sizeof(matrix));
    result->sizeX = n;
    result->sizeY = m;
    result->matrix = malloc(sizeof(double)*m);
    for (int i = 0; i<m; i++){
        result->matrix[i] = malloc(sizeof(double)*n);
    }

    return result;
}

matrix* transpose(matrix M){ //No tested and add verification to see if the matrix contain value
    matrix* result = createMatrix(M.sizeY,M.sizeX);
    for (int x; x<M.sizeX; x++){
        for (int y; y<M.sizeY; y++){
            result->matrix[y][x] = M.matrix[x][y];
        }
    }
    return result;
}

int main(){
    return 0;
}