#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char str[16] = "Example string"; 
    // Stack-də 16 elementlik char array yaradılır
    // İçində "Example string" + null terminator (\0) var
    // Qalan 16-cı element compiler tərəfindən 0 ilə doldurulur, buna görə iki \0 görmək normaldır

    // &str[0] → ilk elementin ünvanı
    // %s → pointer-i alır və \0 görünənə qədər bütün stringi çap edir
    printf("Value: %s\n", &str[0]);  

    // str → array adı, array-in ilk elementinin ünvanı ilə eyni
    printf("Address of str: %p\n", str);      

    // str + 1 → pointer aritmetikası, ikinci elementin ünvanı
    printf("Address of str + 1: %p\n", str + 1);  

    // &str → array-in özünün ünvanı (tip: char (*)[16])
    // &str + 1 → pointer aritmetikası: 1 array boyu (16 byte) irəli gedir
    printf("Address of &str + 1: %p\n", &str + 1);

    // sizeof(str) → array-in bütün ölçüsü, char[16] → 16 byte
    printf("Size of array (str): %llu bytes\n", sizeof(str));

    // sizeof(&str[0]) → ilk elementin pointer-i, 64-bit sistemdə 8 byte
    printf("Size of pointer to first element (&str[0]): %llu bytes\n", sizeof(&str[0]));

    return 0;
}