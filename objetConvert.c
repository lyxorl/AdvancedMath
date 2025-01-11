#include "AdvancedMath.h"

Obj floatToObj(float d){

    Obj result;
    result.type = FLOAT;
    result.value = malloc(sizeof(float));
    *(float *)(result.value) = d;

    return result;

}