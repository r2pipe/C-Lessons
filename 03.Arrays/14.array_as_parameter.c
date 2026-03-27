#include <stdlib.h>
#include <stdio.h>

// Funksiya 2D array-in pointer-to-array forması ilə parametr kimi qəbul edir
// arrParam → hər row-un ilk elementinin ünvanını göstərir, row ölçüsü 5-dir
void printSize(int (*arrParam)[5]){
    // Funksiya daxilində sizeof(arrParam) yalnız pointer ölçüsünü göstərəcək
    printf("Funksiyada array-in ölçüsü (pointer ölçüsü) %llu\n", sizeof(arrParam));

    // İlk row və ilk column elementini dəyişirik
    arrParam[0][0] = 10;

    // 2-ci row, 3-cü column elementini dəyişmək üçün linear indexing və ya row/col istifadə edə bilərik
    arrParam[2][2] = 20; // arr[2][2] = 20
}

int main(int argc, char* argv[]){
    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    };

    // Main daxilində array-in tam ölçüsünü göstəririk (5*5*4 = 100 byte, əgər int=4 byte)
    printf("Main-də array-in ölçüsü %llu\n", sizeof(arr));

    // Funksiyaya array-in ilk row-un ünvanını ötürürük
    printSize(arr);

    // Dəyişiklikləri yoxlamaq üçün çap edirik
    printf("Arr[0][0] = %d\n", arr[0][0]); // 10
    printf("Arr[2][2] = %d\n", arr[2][2]); // 20

    return 0;
}

/*
1D Array funksiyaya ötürülməsi
int arr[5] funksiyaya ötürüləndə pointer kimi davranır: int* arrParam
Funksiya daxilində sizeof(arrParam) → pointer ölçüsünü göstərir, array ölçüsü deyil
Elementlərə arrParam[i] ilə daxil olmaq olar

2D Array funksiyaya ötürülməsi
int arr[5][5] → funksiyaya ötürüləndə pointer to array of 5 ints kimi qəbul edilir: int (*arrParam)[5]
int** arrParam istifadə etmək yanlışdır, çünki 2D array contiguous memory-də yerləşir, pointer-to-pointer isə row-ların ayrı-ayrı pointer-lərdə olmasını gözləyir
Elementlərə arrParam[row][col] ilə daxil olmaq olar
Alternativ linear index: arrParam[row * num_cols + col]

Pointer və Linear Index
Row-major order: row * num_cols + col → linear index
arrParam[2*5 + 2] = arrParam[12] → eyni element
Linear index istifadə etmək olar, amma row*cols + col daha oxunaqlı olur

sizeof
Funksiya daxilində sizeof(arrParam) → həmişə pointer ölçüsü göstərir
Array-in ölçüsünü bilmək üçün ya sizeof(arr) main-də istifadə et, ya da row və col parametrləri funksiyaya ötürülməlidir

Dinamik array of pointers
int** yalnız pointer-to-pointer formatında yaradılmış dinamik array-lar üçün işləyir:
int** arr = malloc(rows * sizeof(int*));
for(int i=0;i<rows;i++)
    arr[i] = malloc(cols * sizeof(int));
Bu memory layout multi-dimensional contiguous array ilə eyni deyil

Məsləhət
Statik 2D array üçün pointer-to-array istifadə et: int (*arrParam)[N]
Linear index istifadə edərkən row-major order-u nəzərə al
int** ilə qarışdırma, type mismatch olacaq və compile error verəcək
*/