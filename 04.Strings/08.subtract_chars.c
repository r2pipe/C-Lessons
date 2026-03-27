#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    char c;
    printf("Enter a character: ");
    scanf(" %c", &c);  // boşluq format specifier-in əvvəli → öncəki newline-ları atmaq üçün

    char original = c;  // original simvolu saxlamaq
    c -= 3;             // ASCII dəyərindən 3 çıxılır

    printf("\nOriginal character: %c (ASCII: %d)\n", original, original);
    printf("After subtraction : %c (ASCII: %d)\n", c, c);

    // Qısa izah:
    // 'd' -> ASCII 100
    // 100 - 3 = 97 -> 'a'
    // Char-lar C-də integer kimi saxlanılır, ona görə çıxarma əməliyyatı mümkündür.

    return 0;  
}