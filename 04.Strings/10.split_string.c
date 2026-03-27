#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    char str[] = "Let's break    this string into pieces";

    // strtok funksiyası ilə string-i "token"lara bölürük
    // " " → delimiter, yəni hər boşluqda string-i kəsəcək
    char* piece = strtok(str, " ");  // İlk token-i alır

    // token bitənə qədər loop
    while(piece != NULL){
        printf("%s\n", piece);        // token-i çap edirik
        piece = strtok(NULL, " ");    // növbəti token-i alır
        // NULL → əvvəlki stringin qalan hissəsindən token götür
    }

    // strtok orijinal string-i **modifies edir**, yəni boşluqları '\0' ilə əvəz edir
    // Tək-tək token-ları pointer-larla əldə edirik

    return 0;  
}