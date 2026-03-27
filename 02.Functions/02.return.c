#include <stdio.h>
#include <stdlib.h>

// Fibonacci function: n-ci Fibonacci ədədini hesablayır və qaytarır
int fibo(int k){
    // n1 = əvvəlki Fibonacci ədədi
    // n2 = indiki Fibonacci ədədi
    int n1, n2, x;
    int i;

    n1 = 0; // 0-cı Fibonacci
    n2 = 1; // 1-ci Fibonacci

    // Loop ilə Fibonacci ədədlərini hesablayırıq
    // İlk iki ədəd artıq məlumdur, ona görə k-2 dəfə dövr edirik
    for(i = 0; i < k - 2; i++){
        x = n2;       // n2-ni saxlayırıq (sonrakı n1 üçün)
        n2 = n1 + n2; // yeni Fibonacci ədədi = əvvəlki iki ədədin cəmi
        n1 = x;       // n1-i güncəlləyirik (öncəki n2 oldu)
    }

    // Çap edirik (optional, dərs üçün)
    printf("The %dth number: %d\n", k, n2); // Ideal deyil: function yalnız dəyər qaytarmalıdır

    // Return: function-un nəticəsini main-ə göndəririk
    return n2;
}

int main(int argc, char* argv[]){
    // Fibonacci function çağırılır və nəticə 'r' dəyişəninə qoyulur
    int r = fibo(6);

    // İstəyə bağlı: r-ə baxmaq üçün çap edə bilərik
    printf("Returned value stored in r: %d\n", r);

    return 0; // main function-u problemsiz bitir
}