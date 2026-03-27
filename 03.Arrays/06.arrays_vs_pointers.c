#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    // STACK-də yaradılır (avtomatik yaddaş)
    int arr[] = {1, 2, 3};

    // Bu sətirlər redundant-dır (zaten yuxarıda verdin)
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    // arr -> ilk elementin ünvanıdır (int*)
    // Yəni arr = &arr[0]
    int* arrp = arr;

    // HEAP-də yaddaş ayrılır (manual control)
    int* p = malloc(3 * sizeof(int));

    // Heap-də olan array-i doldurursan
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;

    // ÜNVANLARI çap edirik
    printf("%p %p %p\n", arr, arrp, p);

    // Heap yaddaşı özün azad etməlisən
    free(p);
}

/*
=== ARRAY vs POINTER (C-də əsas fərqlər) ===

arr (array):
- Stack-də saxlanılır
- Ölçüsü sabitdir (3 element)
- Adı dəyişdirilə bilməz (arr = başqa şey; ERROR)
- Avtomatik silinir (function bitəndə)
- arr -> &arr[0] kimi davranır (amma özü pointer deyil)

arrp (pointer to arr):
- Stack-də saxlanılır
- arr-in ünvanını tutur
- Dəyişdirilə bilər (arrp = p; olar)

p (dynamic pointer - malloc):
- Heap-də yaddaş ayırır
- Ölçü dinamikdir (malloc ilə)
- Manual idarə olunur (free etmək vacibdir)
- Dəyişdirilə bilər
- free(p) etməsən → memory leak

Əsas fərq:
array = sabit, təhlükəsiz, avtomatik
pointer = elastik, güclü, amma riskli (manual control)

Qayda:
arr → system idarə edir
p   → sən idarə edirsən
*/