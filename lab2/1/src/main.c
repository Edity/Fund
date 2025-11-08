#include "../include/func.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>


int main(int argc, char* argv[]) {
    ErrorManager argcheck = countarg(argc);
    if(argcheck != FINE) {
        errorprint(argcheck);
        return 1;       
    }

    int base = 7;
    int n = 2;
    bool ans[n];

    ErrorManager algcheck = check(base, ans, n, 0.33333333, 1.0/7.0);
    if(algcheck != FINE) {
        errorprint(algcheck);
        return 1;
    }

    int i = 0; 

    for (i; i < n; i++) {
        ansprint(ans[i]);
    }

    return 0;
}