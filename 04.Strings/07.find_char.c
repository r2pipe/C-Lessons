#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    char str[] = "Hello, friend!";  

    // strrchr() funksiyası stringdə **sonuncu** uyğun simvolu tapır
    // strchr() isə **ilk uyğun simvolu** tapır
    char* result = strchr(str, 'e');  

    // result NULL yoxlanılır
    if(result != NULL){
        printf("Character was found!\n");

        // Pointer subtraction ilə tapılan simvolun indeksi hesablanır
        // result - str → simvolun 0-based indexi
        int pos = result - str;
        printf("Position: %d\n", pos);
    }else{
        printf("Character was not found!\n");
    }

    return 0;
}

/*
char str[] = "Hello";
char* result = strchr(str, 'l'); // ilk 'l' tapılır

Memory-də:

str[0] = 'H' -> address 0x2000
str[1] = 'e' -> address 0x2001
str[2] = 'l' -> address 0x2002  <-- result
str[3] = 'l' -> address 0x2003
str[4] = 'o' -> address 0x2004

İndeks hesabı:

pos = result - str = 0x2002 - 0x2000 = 2
*/