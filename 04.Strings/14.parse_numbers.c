#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    // String içindəki ədədlər (decimal və hexadecimal)
    char str[] = "200, 0xf";

    // Cursor pointeri stringin başına qoyuruq
    char* cursor = str;

    // Toplama üçün dəyişən
    long int sum = 0;

    // Cursor hələ stringin sonuna çatmayana qədər loop
    while(cursor != str + strlen(str)){
        /**
         * strtol funksiyası: string → long int
         * cursor → oxunacaq yer
         * &cursor → strtol oxuduğu son yeri göstərəcək (dayanılan yer)
         * base = 0 → strtol decimal, octal (0 prefix), və hexadecimal (0x prefix) avtomatik seçir
         */
        long int x = strtol(cursor, &cursor, 0);

        /**
         * Cursor artıq rəqəmlərin sonuna gəlib
         * Boşluq və vergülləri keçmək üçün while loop
         */
        while(*cursor == ' ' || *cursor == ',')
            cursor++; // boşluq və ya ',' keçilir

        // Oxunan ədədi toplamaya əlavə edirik
        sum += x;    
    }

    printf("Sum is %ld\n", sum);

    return 0;
}