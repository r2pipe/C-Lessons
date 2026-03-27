#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>   // isdigit() funksiyasını istifadə etmək üçün lazımdır

int main(int argc, char* argv[]){
    char c = '9';   // yoxlamaq istədiyimiz simvol (char tipi 1 byte-lıq integer-dir)

    // Manual üsul:
    // ASCII cədvəlinə əsasən '0' = 48 və '9' = 57-dir
    // burada simvolun bu intervalda olub-olmadığını yoxlayırıq
    // yəni simvolun rəqəm olub-olmadığını birbaşa memory səviyyəsində müəyyən edirik
    if(c >= '0' && c <= '9'){
        printf("This is a digit: %c\n", c);
    }else{
        printf("This is not a digit: %c\n", c);
    }

    printf("\n");

    // Standard library üsulu:
    // isdigit() funksiyası <ctype.h> kitabxanasına aiddir
    // verilən simvolun rəqəm olub-olmadığını yoxlayır
    // return dəyəri:
    // true  (0-dan fərqli) -> rəqəmdir
    // false (0)           -> rəqəm deyil
    // (unsigned char) cast edilməsinin səbəbi:
    // isdigit() funksiyası unsigned char və ya EOF gözləyir
    // bu cast portability və undefined behavior riskini aradan qaldırır
    if(isdigit((unsigned char)c)){
        printf("This is a digit: %c\n", c);
    }else{
        printf("This is not a digit: %c\n", c);
    }

    return 0; 
}