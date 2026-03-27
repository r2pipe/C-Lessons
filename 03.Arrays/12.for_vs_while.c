#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    
    char text[] = "Hello World!";

    int i;

    // strlen(text) string-in uzunluğunu hesablayır
    // Bunu ayrıca dəyişəndə saxlayırıq ki, hər dövrdə yenidən hesablanmasın
    int len = strlen(text);

    // FOR LOOP:
    // for dövrü adətən iterasiya sayı əvvəlcədən məlum olduqda istifadə olunur
    // Burada string-in uzunluğu məlumdur (len)
    // Ona görə bütün string-i başdan sona qədər çap edirik
    for(i = 0; i < len; i++){
        printf("%c ", text[i]);
    }

    printf("\n");


    // WHILE LOOP:
    // while dövrü iterasiya sayı əvvəlcədən məlum olmadıqda istifadə olunur
    // Burada dayanma şərti boşluq simvoluna (' ') çatmaqdır
    // Yəni boşluğa qədər olan hissə çap olunur ("Hello")
    i = 0;

    while(text[i] != ' '){
        printf("%c ", text[i]);
        i++;
    }


    // NƏTİCƏ:
    // for   -> say (counter) məlumdursa istifadə olunur
    // while -> şərt (condition) əsasında dayanır və iterasiya sayı əvvəlcədən məlum olmaya bilər

    return 0;
}