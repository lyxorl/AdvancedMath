#include "AdvancedMath.h"

complexNumber sumComplexNumber(complexNumber a, complexNumber b){
    
    complexNumber result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;

    return result;
}