#include <stdlib.h>   
#include <stdio.h>    
#include <stdarg.h>   // variadic funksiyalar üçün lazım olan macro-lar

// Variadic funksiya: parametrlərin sayı dəyişkəndir
// count → funksiyaya verilən parametr sayı
int sum(int count, ...){
    va_list args;               // va_list tipi, parametrləri saxlayacaq “handle”
    va_start(args, count);      // args-i initialize edirik, count = son “mütləq” parametr

    int s = 0;                  // toplamı saxlayacaq dəyişən
    int i;
    for(i = 0; i < count; i++){
        int x = va_arg(args, int); // növbəti parametr götür, tipi int
        s += x;                    // toplamı hesabla
    }

    va_end(args);               // va_list-i təmizlə, stack resurslarını boşalt
    return s;                   // cəmi qaytar
}

int main(int argc, char* argv){ 
    // sum funksiyasını çağır, 7 parametr var: 2, 3, 4, 5, 6, 7, 8
    // printf nəticəni çap edir
    printf("Sum is: %d\n", sum(7, 2, 3, 4, 5, 6, 7, 8));

    return 0;
}