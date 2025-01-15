#include "AdvancedMath.h"

Obj floatToObj(float d){

    Obj result;
    result.type = FLOAT;
    result.value = malloc(sizeof(float));
    *(float *)(result.value) = d;

    return result;

}

float objToFloat(Obj o){

    if (o.type != FLOAT){
        printf("Error conversion : This Obj is not a float type");
        exit(1);
    }
    return *(float *)(o.value);
    
}