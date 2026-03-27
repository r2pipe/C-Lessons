#include <stdio.h>
#include <stdlib.h>

// Funksiya: array of string pointers çap edir
void printArray(char** arr, size_t num){
    for(int i = 0; i < num; i++){
        // arr[i] → char* (string-in başlanğıcına pointer)
        printf("%s\n", arr[i]);
    }
}

int main(int argc, char* argv[]){
    // Stack-də writeable char array yaratdıq
    char elem[16] = "Example string";

    // Pointer ref → elem-in başlanğıcına işarə edir
    char* ref = &elem[0];

    // printArray tək bir string-i array kimi qəbul edir
    // &ref → pointer to pointer, çünki funksiyada char** tələb olunur
    printArray(&ref, 1);

    return 0;
}