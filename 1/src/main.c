#include <stdio.h>
#include "../include/funcs.h"

int main(int argc, char* argv[]){
    int x;
    ErrorManager inpcheck = countarg(argc);
    if(inpcheck != FINE){
        errorprint(inpcheck);
        return 1;       
    }
    char *f = argv[2];
    ErrorManager inp2check = inputtry(f);
    if(inp2check != FINE){
        errorprint(inp2check);
        return 1;
    }
    ErrorManager inp1check = makeint(argv[1], &x);
    if(inp1check != FINE){
        errorprint(inp1check);
        return 1;
    }

    if(f[1] == 'h'){
        int n = abs(x);
        ErrorManager hcheck = harg(x, &n);
        if(hcheck != FINE){
            errorprint(hcheck);
            return 1;
        }
    } 
    if(f[1] == 'p'){
        int n = 2, p = 3;
        ErrorManager pcheck = parg(x, &n, &p);
        if(pcheck != FINE){
            errorprint(pcheck);
            return 1;
        }
        primeout(p);
    }
    if(f[1] == 's'){
        ErrorManager scheck = sarg(x);
        if(scheck != FINE){
            errorprint(scheck);
            return 1;
        }
    }
    if(f[1] == 'e'){
        ErrorManager echeck = earg(x);
        if(echeck != FINE){
            errorprint(echeck);
            return 1;
        }
    }
    if(f[1] == 'a'){
        ErrorManager acheck = aarg(x);
        if(acheck != FINE){
            errorprint(acheck);
            return 1;
        }
    }
    if(f[1] == 'f'){
        ErrorManager fcheck = farg(x);
        if(fcheck != FINE){
            errorprint(fcheck);
            return 1;
        }
    }
    return 0;
}