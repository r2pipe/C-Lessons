#include <stdio.h>
#include <stdlib.h>

// Funksiya 1: Tək simvol qaytarır
char getChar(){
    // 'A' tək simvol olduğu üçün burada **pointer lazım deyil**
    // char tipində tək dəyər qaytarır
    return 'A';
}

// Funksiya 2: String qaytarır
char* getString(){
    // "Hello" string literalidir → **read-only memory-də saxlanılır**
    // Qaytaranda **pointer** döndürməliyik, çünki string bir neçə char-dan ibarətdir
    return "Hello";
}

int main(){
    char c = getChar();
    printf("Char: %c\n", c);

    char* s = getString();
    printf("String: %s\n", s);

   
    // 1) getChar() → tək simvol → stack / register-də saxlanır
    // 2) getString() → string literal → memory-də read-only bölmədə saxlanır
    //    Ona görə pointer qaytarmaq lazımdır ki, main funksiyasında istifadə oluna bilsin
    // 3) %c və %s format specifier-ləri tip uyğunsuzluğunu önləyir
    
    return 0;
}