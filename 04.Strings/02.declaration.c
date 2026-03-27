#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    char array[3][50];

    strcpy(array[0], "Hello world!");
    strcpy(array[1], "Test");
    strcpy(array[2], "123456");

    printf("Strings are: \n%s\n%s\n%s\n", array[0], array[1], array[2]);
    puts("\n");

    char array1[3 * 50];

    strcpy(array1, "Hello world!");
    strcpy(array1 + 50, "Test");
    strcpy(array1 + 100, "123456");

    printf("Strings are: \n%s\n%s\n%s\n", array1, array1 + 50, array1 + 100);
    puts("\n");

    char array2[3][50] = {
        "Hello world!", "Test", "123456"
    };
    printf("Strings are: \n%s\n%s\n%s\n", array[0], array[1], array[2]);
    return 0;
}