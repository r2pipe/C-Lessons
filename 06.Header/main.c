#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

// Bu funksiya source string-də substring-i with ilə əvəz edir
// sourceSize → source üçün ayrılmış yaddaş ölçüsü
// Funksiya tapılan substring-in sonrakı ünvanını qaytarır, yoxsa NULL

int main(int argc, char* argv[]){
    char str[100] = "The apples are delicious apples apples apples"; 
    printf("%s\n", str);                                              

    // string içində bütün "apples" sözlərini "hamburgers" ilə əvəz edir
    while(string_replace(str, 100, "apples", "hamburgers")); 

    printf("%s\n", str);                                         
    return 0;                                                       
}