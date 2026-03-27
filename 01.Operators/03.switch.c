#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    char fruit[100];
    printf("What is your favourite fruit?\n");
    fgets(fruit, 100, stdin);
    fruit[strlen(fruit) - 1] = 0; // a p p l e \n \0 , \n → newline (enter), apple\n uzunluq 6, strlen(fruit) - 1 = 6 - 1 = 5 ; strlen(fruit) - 1 → son simvolun indeksi; '\0' == 0
    // advanced --> fruit[strcspn(fruit, "\n")] = 0;
    
    // switch string (char array) ilə işləyə bilmir
    /*switch(fruit){
        case 0:
            printf("You selected apples\n");
            break;
        case 1:
            printf("You selected lemons\n");
            break;
        case 2:
            printf("You selected oranges\n");
            break;
        default:
            printf("No such fruit\n");
    }*/

    // switch string ilə işləmədiyi üçün if-else istifadə edirik
    // strcmp – iki stringi müqayisə edir. 0 qaytarırsa, demək iki string tam eynidir.
    if (strcmp(fruit, "apples") == 0) {
        printf("You selected apples\n");
    }
    else if (strcmp(fruit, "lemons") == 0) {
        printf("You selected lemons\n");
    }
    else if (strcmp(fruit, "oranges") == 0) {
        printf("You selected oranges\n");
    }
    else {
        printf("No such fruit\n");
    }
    return 0;
}