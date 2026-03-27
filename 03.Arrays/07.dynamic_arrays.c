#include <stdlib.h>
#include <stdio.h>

// Global pointer (heap-də olan array-ə baxacaq)
int* arr;
size_t arrSize = 256;

int main(int argc, char* argv[]){

    // Heap-də array yaradılır və 0 ilə doldurulur
    arr = calloc(arrSize, sizeof(int)); // calloc → sıfırlayır
    if(arr == NULL){ // allocation uğursuz olarsa
        fprintf(stderr, "Array not allocated!\n");
        return 1;
    }

    // Array kimi istifadə (amma arxada pointer var)
    arr[10] = 17;
    printf("%d\n", arr[10]); // 17 çap olunacaq

    // Yeni ölçünü əvvəl ayrıca dəyişəndə saxla (daha təhlükəsizdir)
    size_t newSize = arrSize * 2;

    // realloc üçün TEMP pointer istifadə olunur (ƏN VACİB DETAIL)
    int* temp = realloc(arr, newSize * sizeof(int));
    if(temp == NULL){ 
        // realloc fail oldu → köhnə arr hələ də mövcuddur
        fprintf(stderr, "Realloc failed!\n");
        free(arr); // memory leak olmasın deyə azad edirik
        return 1;
    }

    // realloc uğurlu oldu → artıq yeni pointer istifadə edilir
    arr = temp;
    arrSize = newSize;

    // İstəsən yeni hissəni də istifadə edə bilərsən
    arr[300] = 99; // artıq array böyüyüb (256 → 512)

    // İş bitdi → heap yaddaşı azad et
    free(arr);
    arr = NULL; // dangling pointer riskini azaltmaq üçün NULL edilir

    return 0;
}

/*
=== MEMORY ALLOCATION FUNCTIONS ===

1️⃣ malloc(size)
- Heap-də `size` byte yer ayırır
- AYRILAN YERİN DƏYƏRLƏRİ garbage (undefined) olur
- Return: pointer (void*) → type cast lazım ola bilər
- free() ilə azad edilməlidir

2️⃣ calloc(num, size)
- Heap-də `num*size` byte yer ayırır
- HAMISI sıfır (0) ilə doldurulur
- Return: pointer (void*)
- free() ilə azad edilməlidir
- malloc + memset(0) kimi işləyir

3️⃣ realloc(ptr, new_size)
- Mövcud heap pointer-i yeni ölçüyə uyğun böyüdür
- Uğurlu olarsa → pointer eyni və ya yeni ünvan
- Uğursuz olarsa → NULL, köhnə pointer hələ mövcuddur
- Risk: birbaşa `ptr = realloc(ptr, ...)` yazmaq memory leak yarada bilər
- Təhlükəsiz yol: temp pointer ilə yoxla, sonra əvəz et

4️⃣ fprintf(stderr, "message")
- Console-da error mesajlarını çap etmək üçün istifadə olunur
- stderr → standart error stream
- Advantage: normal printf output-dan ayrıdır
- Debug və error handling üçün faydalıdır

=== Summary ===
- malloc → allocate garbage memory
- calloc → allocate zeroed memory
- realloc → resize existing memory (careful!)
- fprintf(stderr, ...) → print errors safely

*/