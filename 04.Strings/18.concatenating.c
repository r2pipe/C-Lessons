#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    char str1[100] = "My name is "; // 100 simvolluq buffer və başlanğıc string
    char str2[] = "Bob Jordan";     // əlavə olunacaq string

    // strcat(str1, str2); // təhlükəli versiya: buffer overflow riski var
    strncat(str1, str2, 100 - strlen(str1) - 1); 
    // strncat:
    // 1️⃣ str1 → target buffer
    // 2️⃣ str2 → əlavə olunacaq string
    // 3️⃣ maksimum əlavə olunacaq simvol sayı (buffer overflow qarşısını alır)
    // 100 - strlen(str1) - 1 → mövcud str1-in uzunluğunu nəzərə alır və son null terminator üçün -1 edir

    printf("%s\n", str1);

    return 0;
}