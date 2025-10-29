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
double d_pow(double x, double y);
int factorial(int x);
int i_clamp(int x, int min, int max);
double d_clamp(double x, double min, double max);
int i_max(int a, int b);
double d_max(double a, double b);
int i_min(int a, int b);
double d_max(double a, double b);
double mean(double* arr, size_t len);
double stddev(double* arr, size_t len);
double mu_sqrt(double x, double epsilon);
int i_abs(int x);
double d_abs(double x);
