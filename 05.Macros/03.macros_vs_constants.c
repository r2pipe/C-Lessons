#include <stdio.h>
#include <stdlib.h>
/*
Macro:       #define MAX 100
             - Preprocessor mərhələsində compile-time-dan əvvəl əvəz olunur
             - Type yoxlaması yoxdur
             - Scope yoxdur, sadəcə mətn əvəzlənir
             
Constant:    const int MAX = 100;
             - Typed variable-dır
             - Compiler type check edir
             - Scope-ludur
             - Runtime-da ünvanını almaq mümkündür
*/

#define MAX 100
// const int MAX = 100;

int main(int argc, char* argv[]) {

    // 1️⃣ Compile-time array ölçüsü
    int arr[MAX];  
    printf("Array of size %d created\n", MAX);

    // 2️⃣ MAX-dan dəyər kimi istifadə
    int a = MAX;
    printf("Value of a: %d\n", a);

    // 3️⃣ Ünvan almağa çalışmaq
    // Macro üçün bu mümkün deyil
    // Constant üçün mümkündür
    #ifdef USE_CONST
        printf("Address of MAX: %p\n", (void*)&MAX);
    #else
        // printf("Address of MAX: %p\n", (void*)&MAX); // ❌ Error if macro
    #endif

    // 4️⃣ Type yoxlaması
    int b = MAX + 0; // Hər ikisi üçün işləyir
    // char c = MAX; // Compile olar amma type mismatch riski var (const üçün)
    
    return 0;
}