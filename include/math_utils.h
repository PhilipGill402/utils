#pragma once
#include <math.h>
#include <stdio.h>

#define PRECISION 10

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


//TODO: implement pow() to remove math.h header

double r_sin(double x);
double d_sin(double x);
double r_cos(double x);
double d_cos(double x);
int i_pow(int x, int y);
double f_pow(double x, double y);
int factorial(int x);
