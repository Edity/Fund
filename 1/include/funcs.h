#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef enum{
    FINE,
    INPUT_ERROR,
    WRONG_FLAG_ERROR,
    NEGATIVE_VALUE_ERROR,
    OUT_OF_RANGE_ERROR,
    OVERFLOW_ERROR,
    NEGATIVE_ERROR,
    NUMBER_OF_ARG_ERROR,
    DIVISION_BY_ZERO_ERROR

} ErrorManager;

ErrorManager harg(const int a, int *i);
ErrorManager parg(const int a, int* i, int* p);
ErrorManager sarg(const int a);
ErrorManager earg(const int a);
ErrorManager aarg(const int a);
ErrorManager farg(const int a);
ErrorManager inputtry(const char* b);
ErrorManager countarg(const int a);
void errorprint(const ErrorManager a);
void primeout(const int a);
int makeint(char* b, int *a);
#endif