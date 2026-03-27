#include <stdio.h>

int main(int argc, char* argv[]){
    // 1️⃣ Variant 1: 1D array-i 2D kimi çap etmək
    int arr1D[9] = {2, 7, 8, 9, 5, 4, 10, 32, 98};

    printf("1D array-i 2D kimi çap:\n");
    for(int i = 0; i < 3; i++){      // sətir
        for(int j = 0; j < 3; j++){  // sütun
            printf("%d ", arr1D[i * 3 + j]); // i*3+j → sətir-sütun indeksi
        }
        printf("\n"); // sətir sonu
    }
    printf("\n");

    // 2️⃣ Variant 2: real 2D array (3x3) ilə
    int arr2D[3][3] = {
        {2, 7, 8},
        {9, 5, 4},
        {10, 32, 98}
    };

    printf("2D array ilə çap:\n");
    for(int i = 0; i < 3; i++){        // sətir
        for(int j = 0; j < 3; j++){    // sütun
            printf("%d ", arr2D[i][j]); // sadəcə i və j ilə çağırırıq
        }
        printf("\n");
    }

    return 0;
}