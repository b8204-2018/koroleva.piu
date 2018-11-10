#include "func.h"
#include <cmath>

int hit (float x, float y){
    int rad = floor(sqrt(x*x + y*y));
    if ((rad <= 5.0) && (rad != 0.0)){
        return (10 - rad) % 5;
    }
    else if (rad == 0.0){

        return 5;
    }
    return 0;
}