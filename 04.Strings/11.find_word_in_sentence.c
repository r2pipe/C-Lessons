#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    char str[] = "Apples are good for your health";
    char to_find[] = "good";

    // strstr string içində substring axtarır
    char* result = strstr(str, to_find);  

    if(result != NULL){  // result NULL deyilsa, söz tapılıb
        printf("The word has been found at position: %ld\n", result - str);
    }else{
        printf("The word has not been found\n");
    }
    
    return 0;
}