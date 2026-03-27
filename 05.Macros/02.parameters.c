#include <stdio.h>
#include <stdlib.h>
/*
PRINT_VAR macro-su function-like macro nümunəsidir.
#X və #Y stringification operatorudur.
Bu operator parametr adını string-ə çevirir.
*/
#define PRINT_VAR(X, Y) \
    printf(#X " is %d at address %p\n", X, &X); \
    printf(#Y " is %d at address %p\n", Y, &Y);
/*
SWAP macro-su iki dəyişənin yerini dəyişir.
*/
#define SWAP(A, B)    \
    do {              \
        int temp = A; \
        A = B;        \
        B = temp;     \
    } while(0)


int main(int argc, char* argv[]){
    int a = 15;
    int b = 8;
    printf("%d %d\n", a, b);
    SWAP(a, b);
    printf("%d %d\n", a, b);
    PRINT_VAR(a, b);

    return 0;
}