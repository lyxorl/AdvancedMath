#include "AdvancedMath.h"
#include <stdio.h>
#include <stdbool.h>

complexNumber nullComplexNumber(){

    complexNumber result;
    result.real = 0;
    result.imaginary = 0;
    return result;
}

complexNumber sumComplexNumber(complexNumber a, complexNumber b){
    
    complexNumber result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;

    return result;
}

complexNumber productComplexNumber(complexNumber a, complexNumber b){
    
    complexNumber result;
    result.real = a.real*b.real - a.imaginary*b.imaginary;
    result.imaginary = a.real*b.imaginary + a.imaginary*b.real;

    return result;
    
}

complexNumber conjugateComplexNumber(complexNumber a){
    
    complexNumber result;
    result.real = a.real;
    result.imaginary = (-1)*a.imaginary;

    return result;
}

Obj modulusComplexNumber(complexNumber a){

    Obj result;
    result = floatToObj((sqrt(a.real*a.real+a.imaginary*a.imaginary)));

    return result;
}

void printComplexNumber(complexNumber a, bool bracket, int prec, int limit_char){

    // prec for precision indicate number we want after comma
    // add option to limit decimal print ...
    // add limit max char for good formatting with other items
    // need to make limit_char and add condition because that conatain at min 4 char with "a+ib" and car with bracket too


    char format[10]; // contain data to print
    snprintf(format, sizeof(format), "%%.%df", prec);

    if (bracket){
        printf("(");
    }
    printf(format, a.real);
    printf("+i");
    printf(format, a.imaginary);
    if (bracket){
        printf(")");
    }
}