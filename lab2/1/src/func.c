#include "../include/func.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

ErrorManager check(const int base, bool* res, const int count, ...) {
    if (base < 2) {
        return WRONG_BASE_ERROR;
    }
    if (res == NULL) {
        return POINTER_ERROR;
    }   
    if (count < 0) {
        return NEGATIVE_VALUE_ERROR;
    }
    if (count == 0) {
        return ZERO_VALUE_ERROR;
    }
    va_list args;
    va_start(args, count);

    const int maxd = 1000000;
    const double eps = 1e-12;
    int i = 0;

    for (i = 0; i < count; i++) {
        double a = va_arg(args, double);

        if (a <= eps || a >= (1.0 - eps)) {
            return OUT_OF_RANGE_ERROR;
        }

        int best_num = 0;
        int best_den = 1;
        double best_dif = 1.0;
        
        int g = 1;
        for (g; g <= maxd; g++) {
            int num = (int)(a * g + 0.5);
            
            if (num <= 0 || num >= g) {
                continue;
            }

            double error = (double)num / g - a;

            if (error < 0) {
                error = -error;
            }
            
            if (error < best_dif) {
                best_dif = error;
                best_num = num;
                best_den = g;
                
                if (error < eps) {
                    break;
                }
            }
        }

        int gcd_val = nod(best_num, best_den);
        int a1 = best_num / gcd_val;
        int d = best_den / gcd_val;

        bool* mnoj = NULL;
        ErrorManager mnojcheck = getmnoj(d, &mnoj);

        if (mnojcheck != FINE) {
            va_end(args);
            return mnojcheck;
        }

        int j = 0;
        bool flag = true;

        for (j = 2; j <= d; j++) {
            if (mnoj[j] && (d % j == 0)) {
                if (base % j != 0) {
                    flag = false;
                    break;
                }
            }
        }

        res[i] = flag;
        free(mnoj);
    }
    va_end(args);
    return FINE;
}

ErrorManager getmnoj(const int a, bool** buff){
    if (buff == NULL) {
        return POINTER_ERROR;
    }
    if (a < 0) {
        return OVERFLOW_ERROR;
    }

    *buff = malloc((a + 1) * sizeof(bool));
    if (*buff == NULL) {
        return MEMORY_ERROR;
    }

    int i = 0;

    for (i = 0; i <= a; i++) {
        (*buff)[i] = (i >= 2);
    }

    for (i = 2; i * i <= a; i++) {
        if ((*buff)[i]) {
            int j = i * i;
            for (j; j <= a; j += i) {
                (*buff)[j] = false;
            }
        }
    }
    return FINE;
}

int nod(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool compare(const double a, const double b, const double eps) {
    return ((a - b) > eps);
}

bool equal(const double a, const double b, const double eps) {
    double diff = a - b;
    if (diff < 0) diff = -diff;
    return (diff < eps);
}

ErrorManager countarg(const int a) {
    if (a != 1) {
        return NUMBER_OF_ARG_ERROR;
    }
    return FINE;
}

void ansprint(const bool a) {
    if (a) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}

void errorprint(const ErrorManager a){
    if(a == ZERO_VALUE_ERROR) printf("ZERO_VALUE_ERROR\n");
    if(a == WRONG_BASE_ERROR) printf("WRONG_BASE_ERROR\n");
    if(a == NEGATIVE_VALUE_ERROR) printf("NEGATIVE_VALUE_ERROR\n");
    if(a == OUT_OF_RANGE_ERROR) printf("OUT_OF_RANGE_ERROR\n");
    if(a == NUMBER_OF_ARG_ERROR) printf("NUMBER_OF_ARG_ERROR\n");
    if(a == POINTER_ERROR) printf("POINTER_ERROR\n");
    if(a == MEMORY_ERROR) printf("MEMORY_ERROR\n");
    if(a == OVERFLOW_ERROR) printf("OVERFLOW_ERROR\n");
}