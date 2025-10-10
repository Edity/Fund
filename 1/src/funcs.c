#include "../include/funcs.h"
#include <limits.h>
#include <ctype.h>

ErrorManager harg(const int a, int *i){
    printf("Multiples of %d:\n", a);
    if(a==0){ 
        printf("Nothing here...\n");
        return FINE;
    }
    while(*i<=100){
        printf("%d\n", *i);
        *i+=abs(a);
    }
    if(*i==abs(a)) printf("Nothing here...\n");
    return FINE;
}

ErrorManager parg(const int a, int* i, int* p){
    if(a<0) return NEGATIVE_VALUE_ERROR;
    if(a<2){
        *p=2;
        return FINE;
    }

    if(a==2){
        *p=1;
        return FINE;
    }
    for((*i);(*i)<=(a/2);(*i)++){
        if(a%(*i)==0) return FINE;
    }
    *p=1;
    return FINE;
}



ErrorManager sarg(const int a){
    int i=abs(a), d;
    char buff[64];
    if(i==0){
        buff[0]='0';
        buff[1]='\0';
        printf("%s\n", buff);   
        return FINE;
    }
    char *p=buff + 63;
    *p = '\0';
    while(i){
        d=i%16;
        if(d>9){
            *--p=('A'+ d-10);
            *--p=' ';
        }
        else{
            *--p=('0' + d);
            *--p=' ';
        }
        i/=16;
    }
    if(a<0) *--p='-';
    if(*p==' ') p++;
    printf("%s\n", p);
    return FINE;
}

ErrorManager earg(const int a){
    if(a>10 || a<1) return OUT_OF_RANGE_ERROR; 
    int i=1,j=1;
    for(i=1;i<=10;i++){
        for(j=1;j<=a;j++){
            printf("%.0f ", pow(i, j));
        }
        printf("\n");
    }
    return FINE;
}

ErrorManager aarg(const int a){
    if(a<0) return NEGATIVE_ERROR;
    int i=1;
    long long sum = 0;
    for(i; i<=a; i++){
        if(LLONG_MAX-i<sum) return OVERFLOW_ERROR;
        sum+=i;
    }
    printf("%lld\n", sum);
    return FINE;
}

ErrorManager farg(const int a){
    if(a<0) return NEGATIVE_ERROR;
    int i=1;
    long long m = 1;
    for(i; i<=a; i++){
        if(LLONG_MAX/i<m) return OVERFLOW_ERROR;
        m*=i;
    }
    printf("%lld\n", m);
    return FINE;
}

ErrorManager inputtry(const char* b){
    if((b[0]!='-'&&b[0]!='/')||b[0]==' '||b[2]!='\0') return INPUT_ERROR;
    if(b[1]!='h'&&b[1]!='p'&&b[1]!='s'&&b[1]!='e'&&b[1]!='a'&&b[1]!='f') return WRONG_FLAG_ERROR;
    return FINE;
}

ErrorManager countarg(const int a){
    if(a!=3) return NUMBER_OF_ARG_ERROR;
    return FINE;
}

int makeint(char* b, int *a){
    *a = 0;
    char *p = b; 
    int z = 1;
    if(*p == '-'){
        z = -1;
        p++;
    }
    while(*p){
        if(!isdigit(*p)) return INPUT_ERROR;
        if(INT_MAX/10 < *a) return OVERFLOW_ERROR;
        *a = *a * 10 + (*p - '0');
        p++;
    }
    *a*=z;
    return FINE;
}

void primeout(const int a){
    if(a==1) printf("it is prime number.\n");
    if(a==2) printf("it is not prime or composite number.\n");
    if(a==3) printf("it is composite number.\n");
}

void errorprint(const ErrorManager a){
    if(a == INPUT_ERROR) printf("INPUT_ERROR\n");
    if(a == WRONG_FLAG_ERROR) printf("WRONG_FLAG_ERROR\n");
    if(a == NEGATIVE_VALUE_ERROR) printf("NEGATIVE_VALUE_ERROR\n");
    if(a == OUT_OF_RANGE_ERROR) printf("OUT_OF_RANGE_ERROR\n");
    if(a == OVERFLOW_ERROR) printf("OVERFLOW_ERROR\n");
    if(a == NEGATIVE_ERROR) printf("NEGATIVE_ERROR\n");
    if(a == NUMBER_OF_ARG_ERROR) printf("NUMBER_OF_ARG_ERROR\n");
    if(a == DIVISION_BY_ZERO_ERROR) printf("DIVISION_BY_ZERO_ERROR\n");
}