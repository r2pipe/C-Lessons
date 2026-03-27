/*
Recursive function → function-un özünü öz daxilində çağırmasıdır.
Başqa sözlə: function problemi özünün daha kiçik bir versiyası ilə həll edir.
Hər recursive function-da 2 vacib hissə var:
Base case → dayandırma şərti, recursion-un bitməsi üçün.
Recursive case → function-un özünü çağırdığı hissə.

int factorial(int n){
    if(n == 0)        // base case
        return 1;
    else
        return n * factorial(n-1); // recursive case
}
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Rekursiv funksiya: x-dən 0-a qədər bütün ədədləri toplayır
int f(int x){
    if(x < 0){    // Base case: x mənfi olduqda rekursiyanı dayandır
        return 0; // Əvvəlki çağırışlar üçün 0 qaytarır
    }

    printf("Hello from f with x = %d\n", x); 

    // Rekursiv addım: x-i f(x-1) nəticəsinə əlavə edir
    // x = 5:
    // f(5) = 5 + f(4) = 5 + (4 + f(3)) = 5 + (4 + (3 + f(2))) ...
    return x + f(x - 1);         
}

int main(int argc, char* argv[]){
    int result = f(5);          
    printf("The result of calling f is %d\n", result); 
    

    return 0; 
}