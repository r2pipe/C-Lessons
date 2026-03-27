#include <stdio.h>
#include <stdlib.h>

int main() {
    char str1[] = "12345";
    char str2[] = "1011";
    char str3[] = "3.14159";
    char* endPtr;

    /** 
     * strtol: string → long int
     * parametrlər:
     *   str → çevriləcək string
     *   &endPtr → çevrilmə zamanı dayanılan yeri göstərir
     *   base → 2, 8, 10, 16 kimi ədəd sistemi
     * qayıdan dəyər → çevrilmiş long int
     */
    long int x = strtol(str1, &endPtr, 10); 
    printf("strtol: %ld\n", x);

    /**
     * strtoul: string → unsigned long int
     * oxşardır strtol ilə, amma nəticə həmişə unsigned long olur
     */
    unsigned long int y = strtoul(str2, &endPtr, 2); // binary
    printf("strtoul: %lu\n", y);

    /**
     * strtod: string → double
     * onluq ədədləri (float/double) çevirmək üçün istifadə olunur
     * base parametrinə ehtiyac yoxdur
     */
    double pi = strtod(str3, &endPtr);
    printf("strtod: %f\n", pi);

    /**
     * strtof: string → float
     * strtod-un float versiyası
     */
    float f = strtof(str3, &endPtr);
    printf("strtof: %f\n", f);

    /**
     * strtoll: string → long long int
     * böyük ədədlər üçün strtol variantı
     */
    long long int big = strtoll("9223372036854775807", &endPtr, 10);
    printf("strtoll: %lld\n", big);

    /**
     * strtoull: string → unsigned long long int
     * böyük unsigned ədədlər üçün
     */
    unsigned long long int ubig = strtoull("18446744073709551615", &endPtr, 10);
    printf("strtoull: %llu\n", ubig);

    return 0;
}