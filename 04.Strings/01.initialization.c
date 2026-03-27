#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    // 1️⃣ Stack-də yaradılmış array, mutable
    char str1[] = "Hello";       // str1 stack-də array kimi yaradılır
    printf("%s\n", str1);        
    str1[0] = 'h';               // array mutable olduğundan dəyişiklik mümkündür
    printf("%s\n", str1);        
    
    puts("\n");

    // 2️⃣ Heap-də yaradılmış string, mutable
    char *str2 = malloc(50 * sizeof(char));  // heap-də 50 char üçün yer ayrılır
    strcpy(str2, "Hello");                   // "Hello" string-i heap-dəki yerə kopyalanır
    printf("%s\n", str2);                     
    str2[0] = 'h';                           // heap-də olduğu üçün dəyişdirilə bilər
    printf("%s\n", str2);                    
    free(str2);                              // heap yaddaşını azad edirik

    puts("\n");

    // 3️⃣ String literal pointer, read-only memory
    char *str3 = "Hello";      // str3 read-only memory-dəki literal-ə işarə edir
    printf("%s\n", str3);      

    // str3[0] = 'h';          // ❌ Səhv! literal read-only memory-də olduğu üçün yazmaq undefined behavior
                               // proqram crash edə bilər (segmentation fault)
    // printf("%s\n", str3);   // bu sətir işləməyəcək əgər yuxarıdakı dəyişiklik aktiv olsa

    return 0;
}