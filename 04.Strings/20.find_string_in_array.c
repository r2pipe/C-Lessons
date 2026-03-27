#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // tolower funksiyası üçün

int main(int argc, char* argv[]){
    char arr[3][100] = {"apple", "orange", "programmer"};  // 3 string-lik array, hər biri max 100 simvol
    char input[100];                                       // istifadəçidən alınacaq söz

    printf("Input a word: ");                             
    fgets(input, 100, stdin);                              // inputu oxuyur (newline da daxil olur)
    input[strlen(input) - 1] = 0;                          // newline '\n' simvolunu silir

    int i;
    for(i = 0; i < strlen(input); i++){                    // inputu kiçik hərflərə çevirir
        input[i] = tolower(input[i]);
    }

    for(i = 0; i < 3; i++){                                // arraydə bütün elementləri yoxlayır
        if(strcmp(arr[i], input) == 0){                    // strcmp → iki string eynidirsə 0 qaytarır
            printf("Found input string at index %d\n", i); // tapılanda index-i çap edir
            break;                                         // tapdıqdan sonra döngüdən çıxır
        }
    }

    if(i >= 3){                                            // əgər arraydə tapılmadısa
        printf("The input string was not found\n");        // tapılmadığını bildirir
    }

    printf("Value of i is %d\n", i);                       // döngü sonunda i dəyərini göstərir

    return 0;                                          
}