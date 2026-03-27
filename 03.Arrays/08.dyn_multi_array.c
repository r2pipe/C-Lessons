#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

    /* Static 2D array nümunəsi (sadece referans üçün)
    int arr[3][3] = {  
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };
    - Birinci 3 → setir (row) sayı
    - İkinci 3 → sutun (column) sayı
    */

    // Dynamic 2D array üçün pointer-to-pointer istifadə olunur
    int** arr = malloc(sizeof(int*) * 3);  
    // malloc(sizeof(int*) * 3) → heap-də 3 setir üçün pointer sahəsi ayırır

    for(int i = 0; i < 3; i++){
        arr[i] = malloc(sizeof(int) * 3); 
        // hər setir üçün 3 int-lik sutun sahəsi ayırır
        // arr[i] → pointer to i-th row
    }

    // Dinamik array elementlərinə dəyər veririk
    arr[0][0] = 1;  // 0-cı setir, 0-cı sutun
    arr[0][1] = 2;  // 0-cı setir, 1-ci sutun

    // Memory ölçüsünün təxmini hesablanması (compile-time)
    printf("%llu\n", sizeof(arr)        // arr → int** pointer ölçüsü
                       + sizeof(arr[0]) * 3   // 3 setir pointer ölçüsü
                       + sizeof(int) * 3 * 3  // bütün elementlərin ölçüsü (9 int)
                       );

    // Dynamic memory-i boşaltmaq (free) və dangling pointer-lardan qorunmaq
    for(int i = 0; i < 3; i++){
        free(arr[i]);   // hər setir üçün malloc edilmiş memory-i boşalt
        arr[i] = NULL;  // setir pointer-i NULL edərək təhlükəsizləşdir
    }
    free(arr);    // arr pointer-i üçün malloc edilmiş memory-i boşalt
    arr = NULL;   // arr pointer-i də NULL edilir

    return 0;
}