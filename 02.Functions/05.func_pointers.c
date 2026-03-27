#include <string.h>   // string əməliyyatları üçün (bu kodda istifadə olunmur, əlavə edilmiş)
#include <stdlib.h>   // rand(), srand(), malloc() və s.
#include <stdio.h>    // printf() funksiyası üçün
#include <time.h>     // time() funksiyası üçün

// İki ədədin cəmini qaytaran funksiya
int sum(int x, int y){
    return x + y;
}

// İki ədədin hasilini qaytaran funksiya
int prod(int x, int y){
    return x * y;
}

/*
 * Funksiya pointeri qəbul edən funksiya
 * operation → iki int qəbul edən və int qaytaran funksiyanın ünvanıdır
 */
void shouldNotBeChanged(int (*operation)(int, int)){
    srand(time(NULL)); // Random generatoru seed edir, hər run üçün fərqli random
    int a = rand() % 100; // 0-99 arası random ədəd
    int b = rand() % 100; // 0-99 arası random ədəd
    
    // operation pointerindəki funksiyanı çağırır və a, b parametrlərini ötürür
    // nəticəni printf ilə çap edir
    printf("The result of the operation between %d and %d is %d\n", a, b, operation(a, b));
}

int main(int argc, char* argv[]){
    // sum funksiyasının ünvanını operation pointerinə göndəririk
    shouldNotBeChanged(&sum);
    
    // prod funksiyasının ünvanını operation pointerinə göndəririk
    shouldNotBeChanged(&prod);
    
    return 0; 
}