#include <stdio.h>
#include <stdlib.h>

// =======================================================
// 1️⃣ Heap-dən array qaytarmaq (malloc istifadə olunur)
// =======================================================
int* getNextFive_heap(int x){
    int* arr = malloc(5 * sizeof(int)); // Heap-də 5 elementlik array yaratdıq
    for(int i = 0; i < 5; i++){        // Hər elementi doldururuq
        arr[i] = x + i;                 // arr[0]=x, arr[1]=x+1, ... arr[4]=x+4
    }
    return arr;                          // Heapdəki array-i qaytarırıq, təhlükəsizdir
}

// =======================================================
// 2️⃣ Caller tərəfindən array göndərmək (stack istifadə olunur)
// =======================================================
void getNextFive_caller(int x, int arr[5]){
    for(int i = 0; i < 5; i++){         // Caller arrayini doldururuq
        arr[i] = x + i;                  // arr[0]=x, arr[1]=x+1, ...
    }
    // Qaytarmağa ehtiyac yoxdur, çünki caller array-i özündə saxlayır
}

// =======================================================
// 3️⃣ Static array qaytarmaq (funksiya bitəndən sonra da yaşayır)
// =======================================================
int* getNextFive_static(int x){
    static int arr[5];                   // Static array stackdə deyil, data segmentdə yaşayır
    for(int i = 0; i < 5; i++){          // Hər elementi doldururuq
        arr[i] = x + i;                  // arr[0]=x, arr[1]=x+1, ...
    }
    return arr;                           // Qaytarmaq təhlükəsizdir, amma hər çağırışda eyni array-i istifadə edir
}

int main(){
    int x = 5;                            // Başlanğıc dəyərimiz

    // --------- 1️⃣ Heap yolu ----------
    int* heap_result = getNextFive_heap(x); // Heap array-i pointerlə alırıq
    printf("Heap array: ");
    for(int i = 0; i < 5; i++){           // Array-i çap edirik
        printf("%d ", heap_result[i]);    // 5 6 7 8 9
    }
    free(heap_result);                     // Mütləq free etməliyik, yoxsa memory leak olar
    printf("\n");

    // --------- 2️⃣ Caller array yolu ----------
    int caller_arr[5];                     // Stackdə array yaradılır
    getNextFive_caller(x, caller_arr);     // Funksiyaya göndəririk
    printf("Caller array: ");
    for(int i = 0; i < 5; i++){           // Array-i çap edirik
        printf("%d ", caller_arr[i]);      // 5 6 7 8 9
    }
    printf("\n");

    // --------- 3️⃣ Static array yolu ----------
    int* static_result = getNextFive_static(x); // Static array-i pointerlə alırıq
    printf("Static array: ");
    for(int i = 0; i < 5; i++){               // Array-i çap edirik
        printf("%d ", static_result[i]);      // 5 6 7 8 9
    }
    printf("\n");

    return 0; // Proqram bitdi
}

/*
Caller array: funksiyaya ünvan göndərirsən, stackdə qalır, təhlükəsiz.

Static array: funksiyanın daxilində qalır, funksiya bitəndən sonra da yaşayır, 
amma hər çağırışda eyni yaddaş istifadə olunur.

Heap array (malloc): hər çağırışda yeni yaddaş, pointer qaytarılır, amma free etməlisən.
*/