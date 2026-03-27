#include <stdio.h>
#include <stdlib.h>

int main() {
    // Müxtəlif tipdə dəyişənlər
    int a;          // int tipində dəyişən
    char b;         // char tipində dəyişən
    double c;       // double tipində dəyişən

    // Array nümunəsi
    int arr[10];    // 10 elementli int array

    // Pointer nümunəsi
    int *ptr = arr; // int pointer → arr-ın ünvanına işarə edir

    // size_t tipi sizeof operatorundan qaytarılan dəyər üçün istifadə olunur
    size_t size;    // portable unsigned integer tipidir

    // ------------------------
    // 1. Primitive tip dəyişənlərin ölçüsü
    // ------------------------
    size = sizeof(a); 
    printf("Size of int a: %zu bytes\n", size); // %zu → size_t üçün format specifier

    size = sizeof(b);
    printf("Size of char b: %zu bytes\n", size); // char 1 byte-dir

    size = sizeof(c);
    printf("Size of double c: %zu bytes\n", size); // double adətən 8 byte-dir

    // ------------------------
    // 2. Array ölçüsü
    // ------------------------
    size = sizeof(arr); 
    printf("Size of int arr[10]: %zu bytes\n", size); 
    // arr = 10 * sizeof(int) → 10 * 4 = 40 bytes (platforma görə dəyişir)

    // Array-də bir elementin ölçüsü
    size = sizeof(arr[0]);
    printf("Size of arr[0]: %zu bytes\n", size); 
    // bir element = sizeof(int) → 4 bytes

    // Array element sayı hesablanması
    size_t elements = sizeof(arr) / sizeof(arr[0]);
    printf("Number of elements in arr: %zu\n", elements); 
    // 40 / 4 = 10 → array-də 10 element var

    // ------------------------
    // 3. Pointer ölçüsü
    // ------------------------
    size = sizeof(ptr);
    printf("Size of int* ptr: %zu bytes\n", size); 
    // pointer özü ölçülür → 64-bit sistemdə 8 bytes, 32-bitdə 4 bytes

    size = sizeof(*ptr);
    printf("Size of *ptr (dereferenced pointer): %zu bytes\n", size); 
    // pointer-in göstərdiyi tipin ölçüsü → int → 4 bytes

    return 0;
}