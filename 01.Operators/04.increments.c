#include <stdio.h>
#include <string.h>

// ++a → a-nı artırır və dəyəri istifadə edir
// a++ → əvvəl dəyəri istifadə edir, sonra artırır

int main(int argc, char* argv[]){
    int a = 0;
    printf("%d\n", ++a + ++a - ++a + a++); // Undefined behavior var, yəni compiler operatorları istədiyi sırada icra edə bilər
                 // 1 + 2 - 3 + 3 = 3
                 // 4 + 3 - 2 + 0 = 5
}
