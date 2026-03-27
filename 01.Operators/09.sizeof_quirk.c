#include <stdio.h>

int main(int argc, char* argv[]){
    int x = 5; // x dəyişəni int tipindədir və başlanğıc dəyəri 5-dir

    // sizeof operatoruna ++x ifadəsini veririk
    // Maraqlı quirk: sizeof **compile-time operator**-dur
    // Bu o deməkdir ki, ifadənin **dəyəri hesablamaq üçün icra olunmur**, sadəcə tipi yoxlanılır
    printf("Size: %zu\n", sizeof(++x)); 
    // Nəticə: sizeof(int) → 4 (64-bitdə) 
    // ++x burada işlənmir, yəni x dəyişmir

    // x-in dəyəri yoxlayaq
    printf("Value: %d\n", x); 
    // Nəticə: 5 → ++x icra olunmayıb

    return 0;
}