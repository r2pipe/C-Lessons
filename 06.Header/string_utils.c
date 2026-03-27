#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
