#include "AdvancedMath.h"

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