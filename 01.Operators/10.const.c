#include <stdio.h>
#include <stdlib.h>

void printArray(const int arr[], size_t n) {
    // arr const olduğu üçün funksiyada dəyişdirilə bilməz
    printf("Array contents: ");
    for(size_t i = 0; i < n; i++){
        printf("%d ", arr[i]);
        // arr[i] = 10; // ERROR → const olduğu üçün dəyişdirilə bilməz
    }
    printf("\n");
}

int main() {
    // ------------------------
    // 1. Primitive const dəyişən
    // ------------------------
    const int x = 5; // x dəyişdirilə bilməz
    printf("x = %d\n", x);
    // x = 10; // ERROR → compile-time

    // ------------------------
    // 2. Pointer-lərlə const
    // ------------------------
    int a = 100;
    int b = 200;

    const int *ptr1 = &a; // pointer-in göstərdiyi dəyər const → dəyəri dəyişmək olmaz
    // *ptr1 = 101; // ERROR
    ptr1 = &b;            // OK → pointer-i başqa ünvana yönləndirmək olar

    int * const ptr2 = &a; // pointer özü const → ünvan dəyişdirilə bilməz
    *ptr2 = 102;            // OK → dəyəri dəyişmək olar
    // ptr2 = &b;           // ERROR → pointer-i dəyişmək olmaz

    const int * const ptr3 = &a; // həm pointer, həm dəyər const
    // *ptr3 = 103; // ERROR → dəyəri dəyişmək olmaz
    // ptr3 = &b;   // ERROR → pointer-i dəyişmək olmaz

    printf("ptr1 points to %d\n", *ptr1);
    printf("ptr2 points to %d\n", *ptr2);
    printf("ptr3 points to %d\n", *ptr3);

    // ------------------------
    // 3. Array və const
    // ------------------------
    int arr[5] = {1, 2, 3, 4, 5};
    printArray(arr, 5); // funksiyaya const array göndəririk → icra zamanı dəyişdirilə bilməz

    // ------------------------
    // 4. sizeof operatoru ilə birlikdə const
    // ------------------------
    size_t size = sizeof(x); // const int də eyni ölçüdə olur
    printf("Size of const int x: %zu bytes\n", size);

    size = sizeof(arr);      // bütün array-in ölçüsü
    printf("Size of arr: %zu bytes\n", size);

    size = sizeof(ptr1);     // pointer ölçüsü
    printf("Size of ptr1: %zu bytes\n", size);

    return 0;
}