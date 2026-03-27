#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h> // ISO 646 macros üçün: and, or, or_eq, etc.

int main(int argc, char* argv[]){
    // ------------------------
    // 1. Variable initialization
    // ------------------------
    int x = 0;          // x-i 0 olaraq təyin edirik
    x or_eq 1;           // x |= 1 → bitwise OR + assign, nəticə: x = 0 | 1 = 1

    // ------------------------
    // 2. Logical condition using ISO 646 macros
    // ------------------------
    // Şərh:
    // (x >= 10 and x <= 20 or x < 0)
    // - x >= 10        → TRUE, əgər x 10-dan böyük və ya bərabərdirsə
    // - x <= 20        → TRUE, əgər x 20-dən kiçik və ya bərabərdirsə
    // - x >=10 and x <=20 → TRUE yalnız x [10,20] intervalında olarsa
    // - or x < 0       → TRUE, əgər x mənfi olarsa
    // - Ümumi nəticə TRUE → şərt doğrudursa, printf işləyəcək

    if(x >= 10 and x <= 20 or x < 0){
        // Burada x = 1 olduğu üçün:
        // x >= 10 → FALSE
        // x <= 20 → TRUE
        // x >=10 and x <=20 → FALSE and TRUE → FALSE
        // x < 0 → FALSE
        // FALSE or FALSE → FALSE
        printf("Result is true\n"); // bu işləməyəcək, çünki şərt FALSE-dır
    } else {
        printf("Result is false\n"); // bu işləəcək
    }

    // ------------------------
    // 3. ISO 646 qısaca operatorlar nümunəsi
    // ------------------------
    int y = 2;          // başqa dəyişən
    y and_eq 1;          // y &= 1 → bitwise AND + assign, y = 2 & 1 = 0
    printf("y after y and_eq 1: %d\n", y);

    int z = 0;
    z or_eq 3;           // z |= 3 → 0 | 3 = 3
    printf("z after z or_eq 3: %d\n", z);

    int flag = 1;
    if(not flag){         // !flag → FALSE, belə ki, else işləyəcək
        printf("Flag is false\n");
    } else {
        printf("Flag is true\n");
    }

    return 0;
}

/*
Logical → and, or, not, not_eq → TRUE/FALSE səviyyəsində işləyir (1/0)

Bitwise → and_eq, or_eq, xor_eq, bitand, bitor, xor, compl → hər bit üzrə işləyir
*/