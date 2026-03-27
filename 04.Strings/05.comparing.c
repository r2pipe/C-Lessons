#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*  argv[]){
    char str1[] = "abcd1";
    char str2[] = "abcd4";

    printf("%d\n", strcmp(str1, str2));    
    // strcmp iki stringi başdan sona müqayisə edir
    // müqayisə '\0' (null terminator) simvoluna qədər davam edir
    // fərq tapılan ilk simvolun ASCII fərqini qaytarır
    // nəticə:
    // 0  -> stringlər eynidir
    // <0 -> str1 < str2
    // >0 -> str1 > str2
    // burada '1' < '4' olduğu üçün mənfi nəticə çıxacaq


    printf("%d\n", strncmp(str1, str2, 5));
    // strncmp yalnız verilən qədər simvolu müqayisə edir (burada 5 simvol)
    // '\0' görsə belə dayanır
    // ilk 5 simvol:
    // abcd1
    // abcd4
    // yenə '1' və '4' fərqli olduğu üçün mənfi nəticə çıxacaq
    // fərq:
    // strcmp bütün stringi müqayisə edir
    // strncmp isə limit qoyulmuş müqayisə edir


    printf("%d\n", memcmp(str1, str2, 5));
    // memcmp raw memory müqayisə edir (string yox!)
    // '\0' null terminatora fikir vermir
    // sadəcə byte-by-byte müqayisə edir
    // 5 byte müqayisə olunur:
    // a b c d 1
    // a b c d 4
    // '1' və '4' fərqli olduğu üçün mənfi nəticə çıxacaq
    // fərq:
    // strcmp string üçündür
    // memcmp isə ümumi memory blokları üçündür (array, struct və s.)

    return 0;
}