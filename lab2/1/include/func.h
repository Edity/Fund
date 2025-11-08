#ifndef FUNC_H
#define FUNC_H
#include <stdbool.h>

typedef enum{
    FINE,
    ZERO_VALUE_ERROR,
    WRONG_BASE_ERROR,
    NEGATIVE_VALUE_ERROR,
    OUT_OF_RANGE_ERROR,
    NUMBER_OF_ARG_ERROR,
    POINTER_ERROR,
    MEMORY_ERROR,
    OVERFLOW_ERROR
} ErrorManager;

ErrorManager check(const int base, bool* res, const int count, ...);
int nod(int a, int b);
ErrorManager getmnoj(const int a, bool** buff);
bool compare(const double a, const double b, const double eps);
bool equal(const double a, const double b, const double eps);
ErrorManager countarg(const int a);
void ansprint(const bool a);
void errorprint(const ErrorManager a);
#endif