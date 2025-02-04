#include "AdvancedMath.h"
#include <stdio.h>

int main(){

    //first test to print complex number
    complexNumber test;
    test.real = 1.2;
    test.imaginary = 1.2;
    printComplexNumber(test, true,1);
    printf("\n");
    printComplexNumber(test, false,2);
    printf("\n");
    

    return 0;
}