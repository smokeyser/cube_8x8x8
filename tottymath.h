#ifndef TOTTYMATH_H
#define TOTTYMATH_H
#include "cube.h"
#include <math.h>
#define PI 3.14159265
#define LUT_START unsigned char LUT[65];init_LUT(LUT);
void init_LUT(unsigned char LUT[65]);
int totty_sin(unsigned char LUT[65],int sin_of);
int totty_cos(unsigned char LUT[65],int cos_of);
#endif