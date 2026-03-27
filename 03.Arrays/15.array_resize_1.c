#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int* arr = malloc(sizeof(int) * 4);
    int last_index = 0;

    arr[last_index] = 17;
    last_index++;
    arr[last_index] = 18;
    last_index++;
    arr[last_index] = 19;
    last_index++;
    arr[last_index] = 20;
    last_index++;

    int* realloc_result = realloc(arr, sizeof(int) * 8);
    if(realloc_result == NULL){
        printf("Realloc failed for arr");
        return 1;
    }
    arr = realloc_result;
    arr[last_index] = 21;
    last_index++;
    printf("First elemet: %d\n", arr[0]);
    printf("Last element: %d\n", arr[last_index - 1]);
    free(arr);
    return 0;
}