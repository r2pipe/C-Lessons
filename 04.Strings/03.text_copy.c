#include <stdlib.h>   
#include <stdio.h>    
#include <string.h>   

int main(int argc, char* argv[]){ 

    char text1[50];  
    char text2[] = "Temp";
    char text3[17] = "Hello this world";

    //strcpy(text1, text3);         // təhlükəli ola bilər (buffer ölçüsü yoxlanılmır)

    strncpy(text1, text3, sizeof(text1) - 1); // maksimum 49 simvol copy edilir (son byte '\0' üçün saxlanılır)
    text1[sizeof(text1) - 1] = '\0'; // manual null-termination – strncpy '\0' yazmaya bilər deyə təhlükəsizlik addımı

    printf("%s\n%s\n%s\n", text1, text2, text3); 

    return 0;  
}