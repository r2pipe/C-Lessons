#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bu funksiya source string-də substring-i with ilə əvəz edir
// sourceSize → source üçün ayrılmış yaddaş ölçüsü
// Funksiya tapılan substring-in sonrakı ünvanını qaytarır, yoxsa NULL
char* string_replace(char* source, size_t sourceSize, char* substring, char* with){
    char* substring_source = strstr(source, substring); // source içində substring-i axtarır
    if(substring_source == NULL){                       // əgər tapılmazsa, NULL qaytarır
        return NULL;
    }

    // buffer-in kifayət qədər böyük olub olmadığını yoxlayır
    if(sourceSize < strlen(source) + (strlen(with) - strlen(substring)) + 1){
        printf("Buffer size is too small\n");
        return NULL;
    }

    // substring-i with ilə əvəz etmək üçün qalan hissəni sağa itələyirik
    memmove(
        substring_source + strlen(with),                 // yeni sözün başlanğıcı
        substring_source + strlen(substring),            // köhnə sözün sonundan sonrası
        strlen(substring_source) - strlen(substring) + 1 // köçürüləcək uzunluq (+1 = '\0')
    );

    memcpy(substring_source, with, strlen(with));        // substring-i with ilə yazırıq
    return substring_source + strlen(with);              // növbəti əməliyyat üçün pointer qaytarır
}

int main(int argc, char* argv[]){
    char str[100] = "The apples are delicious apples apples apples"; 
    printf("%s\n", str);                                              

    // string içində bütün "apples" sözlərini "hamburgers" ilə əvəz edir
    while(string_replace(str, 100, "apples", "hamburgers")); 

    printf("%s\n", str);                                         
    return 0;                                                       
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bu funksiya source string-də bütün substring-ləri with ilə əvəz edir
// source → dəyişdiriləcək string
// substring → axtarılacaq söz
// with → əvəzləyəcək söz
// Funksiya yeni string-i qaytarır, orijinal source-ı dəyişdirmir
char* string_replace_dynamic(const char* source, const char* substring, const char* with) {
    if (!source || !substring || !with) return NULL;

    size_t sourceLen = strlen(source);
    size_t subLen = strlen(substring);
    size_t withLen = strlen(with);

    // Tapılan substring sayı üçün ilkin say
    size_t count = 0;
    const char* tmp = source;
    while ((tmp = strstr(tmp, substring)) != NULL) {
        count++;
        tmp += subLen;
    }

    if (count == 0) return strdup(source); // substring tapılmazsa, eyni string qaytar

    // Yeni string üçün lazım olan ölçü
    size_t newLen = sourceLen + count * (withLen - subLen);
    char* result = malloc(newLen + 1); // +1 sonlandırıcı üçün
    if (!result) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Orijinal string-i kopyalayaraq əvəzləmə əməliyyatı
    const char* srcPtr = source;
    char* dstPtr = result;
    while ((tmp = strstr(srcPtr, substring)) != NULL) {
        // substring-dən əvvəlki hissəni kopyalayırıq
        size_t prefixLen = tmp - srcPtr;
        memcpy(dstPtr, srcPtr, prefixLen);
        dstPtr += prefixLen;

        // with-i kopyalayırıq
        memcpy(dstPtr, with, withLen);
        dstPtr += withLen;

        srcPtr = tmp + subLen; // növbəti tapış üçün pointer
    }

    // Sonuncu qalan hissəni kopyalayırıq
    strcpy(dstPtr, srcPtr);

    return result;
}

int main() {
    const char* str = "The apples are delicious apples apples apples";
    printf("Original: %s\n", str);

    char* replaced = string_replace_dynamic(str, "apples", "hamburgers");
    if (replaced) {
        printf("Replaced: %s\n", replaced);
        free(replaced); // malloc-un təmizlənməsi
    }

    return 0;
}
*/