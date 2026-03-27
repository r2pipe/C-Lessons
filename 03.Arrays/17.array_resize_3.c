#include <stdio.h>
#include <stdlib.h>

// add_to_array funksiyası
// arr → array pointer-i (double pointer)  
// last_index → növbəti boş index  
// capacity → hazırkı array ölçüsü  
// elem → əlavə olunacaq element
void add_to_array(int** arr, int* last_index, int* capacity, int elem){
    // Əgər array dolubsa, realloc çağır
    if(*last_index >= *capacity){
        // realloc-u minimal artırma ilə çağırırıq: yalnız 1 əlavə element üçün yer
        int* realloc_result = realloc(*arr, sizeof(int) * (*capacity + 1));

        // Biz hər realloc çağırışında mesaj çap edirik ki, neçə dəfə işlədiyini görək
        printf("We reallocated\n");

        // realloc uğursuz olarsa, köhnə memory-ni free et və proqramı dayandır
        if(realloc_result == NULL){
            free(*arr);
            printf("Realloc failed for arr\n");
            exit(1);
        }

        // capacity-ni yalnız 1 artırırıq
        *capacity += 1;

        // arr pointer-i yeni realloc edilmiş memory-ə yönəldilir
        *arr = realloc_result;
    }

    // Yeni element əlavə edilir
    (*arr)[*last_index] = elem;

    // last_index artırılır ki, növbəti element üçün boş yer hazır olsun
    (*last_index)++;
}

int main(int argc, char* argv[]){
    int capacity = 4; // başlanğıc array ölçüsü
    int* arr = malloc(sizeof(int) * capacity); // heap-də yer ayrılır
    int last_index = 0; // növbəti boş index

    // Elementləri əlavə edirik
    add_to_array(&arr, &last_index, &capacity, 17);
    add_to_array(&arr, &last_index, &capacity, 18);
    add_to_array(&arr, &last_index, &capacity, 19);
    add_to_array(&arr, &last_index, &capacity, 20);
    add_to_array(&arr, &last_index, &capacity, 21);
    add_to_array(&arr, &last_index, &capacity, 22);
    add_to_array(&arr, &last_index, &capacity, 23);
    add_to_array(&arr, &last_index, &capacity, 24);
    add_to_array(&arr, &last_index, &capacity, 25);
    add_to_array(&arr, &last_index, &capacity, 26);
    add_to_array(&arr, &last_index, &capacity, 27);
    add_to_array(&arr, &last_index, &capacity, 28);

    // Nəticələri çap edirik
    printf("Capacity: %d\n", capacity);
    printf("Last index: %d\n", last_index);
    printf("First element: %d\n", arr[0]);
    printf("Last element: %d\n", arr[last_index - 1]);

    free(arr); // heap-də ayrılmış yaddaşı azad et
    return 0;
}


/*
1️⃣ Realloc çox tez-tez çağırılır
Hər element əlavə etdikdə realloc çağırılır → last_index >= capacity olduqda.
Hər realloc köhnə array-i yeni memory-ə copy edir.
Məsələn, 1000 element əlavə etsən → təxminən 500k copy əməliyyatı.
Bu çox yavaş və resurs itkisi yaradır.
2️⃣ Minimal artım səmərəsizdir
Yaddaş çox kiçik bloklarla artır → sistem allocator üçün əlavə overhead yaranır.
Exponential growth üsulu isə amortized O(n) əməliyyat yaradır, sənin üsul isə O(n²).
3️⃣ Real sistemlərdə istifadə olunmur
C++ std::vector, Python list, Java ArrayList → capacity-ni 1.5–2 qat artırır.
Minimal artım yalnız öyrənmə məqsədli və ya çox kiçik array-lər üçün istifadə olunur.
*/