#include <stdio.h>
#include <stdlib.h>

// Funksiya array-i (pointer vasitəsilə) qəbul edir və elementləri toplayır
int sum(int* arr, int n){
    int i, s = 0;

    arr[0] = 10; // Caller array-in ilk elementini dəyişir
                  // Bu göstərir ki, array "pass by reference" kimi ötürülüb

    for(i = 0; i < n; i++){
        s += arr[i]; // Bütün elementləri toplayır
    }

    return s; // Cəmi qaytarır
}

int main(int argc, char* argv[]){
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; // Stackdə 7 elementlik array yaradılır
    int s = sum(arr, 7); // array pointeri və ölçüsü funksiyaya göndərilir

    printf("Sum: %d\n", s); // Funksiyada dəyişdirilmiş array ilə cəmi çap edir
    printf("First element: %d\n", arr[0]); // Caller array-in ilk elementi dəyişib (10)
    
    return 0;
}