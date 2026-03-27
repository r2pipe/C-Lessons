#include <stdio.h>

int main() {

    int a = 5;   // decimal 5  → binary: 00000101
    int b = 3;   // decimal 3  → binary: 00000011

    int r;

    // AND operator (&)
    r = a & b;   
    // bitwise AND: yalnız eyni mövqedə iki bit də 1 olsa nəticə 1 olur
    // 00000101
    // 00000011
    // --------
    // 00000001  → decimal 1
    printf("a & b = %d\n", r);

    // OR operator (|)
    r = a | b;
    // bitwise OR: hər hansı bit 1 olsa nəticə 1 olur
    // 00000101
    // 00000011
    // --------
    // 00000111  → decimal 7
    printf("a | b = %d\n", r);

    // XOR operator (^)
    r = a ^ b;
    // bitwise XOR: bitlər fərqli olsa 1 olur
    // 00000101
    // 00000011
    // --------
    // 00000110  → decimal 6
    printf("a ^ b = %d\n", r);

    // NOT operator (~)
    r = ~a;
    // bitwise NOT: bütün bitləri tərsinə çevirir
    // 00000101  (5)
    // 11111010  (two's complement səbəbindən nəticə -6 olur)
    printf("~a = %d\n", r);

    // AND operatorun real istifadə nümunəsi
    int x = 9; // 00001001

    if (x & 1) 
    // son bit 1-dirsə ədəd təkdir
    // 00001001 & 00000001 → 00000001
        printf("x odd number\n");
    else
        printf("x even number\n");

    return 0;
}