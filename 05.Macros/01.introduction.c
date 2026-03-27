#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Function-like(Funksiyaya bənzər) macro nümunəsi.
PRODUCT(X, Y) macro-su parametr qəbul edir və onları vurur.
Macro compiler tərəfindən compile olunmazdan əvvəl işləyir
(preprocessor mərhələsində).
Yəni compiler bu macro-nu görmür — onun yerinə expanded versiyanı görür.
Macro yazarkən hər parametr mötərizə içində yazılmalıdır:
((X) * (Y))
Əks halda expression priority səhvləri yarana bilər.
*/
#define PRODUCT(X, Y) ((X) * (Y))

int main(int argc, char* argv[]){
    int a = 2;
    int b = 6;
    /*
    Burada macro çağırılır:
    PRODUCT(a+1+1, b)
    Preprocessor bunu belə dəyişir:
    ((a+1+1) * (b))
    Sonra compiler bunu normal expression kimi hesablayır.
    */
    printf("%d\n", PRODUCT(a+1+1, b));

    return 0;
}

/*
source.c
↓
preprocessor   (#define, #include, #if, #ifdef və s.)
↓
compiler       (syntax check + assembly generation)
↓
assembler
↓
linker
↓
binary executable
*/

/*
1️⃣ Object-like macros
Sadəcə dəyəri text replacement edir.
Sintaksis:
#define PI 3.14
İstifadəsi: double area = PI * r * r;
Type yoxlaması yoxdur, preprocessor sadəcə əvəzləyir.

2️⃣ Function-like macros
Parametr qəbul edir, amma funksiya yox, text substitution edir.
Sintaksis:
#define SQUARE(x) ((x)*(x))
İstifadəsi: int a = SQUARE(5+1); // -> ((5+1)*(5+1))
Warning: yan təsir (side-effect) riski var: SQUARE(i++) yanlış nəticə verə bilər.

3️⃣ Stringification (#)
Macro parametrini string-ə çevirir.
Sintaksis:
#define TO_STRING(x) #x
printf("%s\n", TO_STRING(Hello)); // prints "Hello"

4️⃣ Token-pasting (##)
İki tokeni birləşdirir, ad yaratmaq üçün istifadə olunur.
Sintaksis:
#define MAKE_VAR(name, num) name##num
int MAKE_VAR(a, 1) = 5; // -> int a1 = 5;

5️⃣ Conditional macros (#ifdef, #ifndef, #if, #elif, #else, #endif)
Compile-time şərtlər üçün.
Sintaksis:
#define DEBUG
#ifdef DEBUG
    printf("Debug mode\n");
#endif

6️⃣ Undefine macros (#undef)
Macro-nu silmək üçün istifadə olunur.
Sintaksis:
#define MAX 100
#undef MAX

7️⃣ Include macros (#include)
Başqa faylları preprocessor mərhələsində əlavə edir.
Sintaksis:
#include <stdio.h>
#include "myheader.h"

8️⃣ Pragma macros (#pragma)
Compiler-ə xüsusi direktivlər üçün istifadə olunur.
Sintaksis:
#pragma pack(1)  // struct alignment
*/