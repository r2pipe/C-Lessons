#include <stdlib.h>
#include <stdio.h>

// Function: iki dəyərin cəmini və hasilini hesablayır
// Pointer-lər vasitəsilə main-dəki sum və prod dəyişənlərini güncəlləyir
// Return int → status, 1 = uğur, 0 = error (NULL pointer)
int sumAndProduct(int a, int b, int *sum, int *prod){
    // NULL pointer yoxlaması → error varsa status 0 qaytar
    // NULL → “heç bir yerə işarə etmir” deməkdir, yəni pointer boşdur.
    if(sum == NULL || prod == NULL){
        return 0;
    }

    // Pointer-lərə yazır → main-dəki sum və prod yenilənir
    *sum = a + b;
    *prod = a * b;

    // Hər şey uğurludur → status 1 qaytar
    return 1;
}

int main(int argc, char* argv[]){
    // Input dəyərlər
    int x = 5, y = 12;

    // Nəticələri saxlamaq üçün dəyişənlər
    int sum, prod;

    // Function çağırılır → pointer-lərə yazır və status qaytarır
    int status = sumAndProduct(x, y, &sum, &prod);

    // Status yoxlanılır
    if(status == 0){
        // Function error qaytardı → çap edirik
        printf("Something went wrong\n");
    }else{
        // Uğurlu oldu → nəticələri çap edirik
        printf("The sum is: %d and the product: %d\n", sum, prod);
    }

    // main problemsiz bitdi → OS-ə signal
    return 0;
}