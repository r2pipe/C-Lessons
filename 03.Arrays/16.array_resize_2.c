#include <stdio.h>
#include <stdlib.h>

void add_to_array(int** arr, int* last_index, int* capacity, int elem){
    if(*last_index >= *capacity){
        int* realloc_result = realloc(*arr, sizeof(int) * *capacity * 2);
        if(realloc_result == NULL){
            free(*arr);
            printf("Realloc failed for arr");
            exit(1);
        }
        *capacity *= 2;
        *arr = realloc_result;
    }
    (*arr)[*last_index] = elem;
    (*last_index)++;
}
int main(int argc, char* argv[]){
    int capacity = 4;
    int* arr = malloc(sizeof(int) * capacity);
    int last_index = 0;

    add_to_array(&arr, &last_index, &capacity, 17);
    add_to_array(&arr, &last_index, &capacity, 18);
    add_to_array(&arr, &last_index, &capacity, 19);
    add_to_array(&arr, &last_index, &capacity, 20);
    add_to_array(&arr, &last_index, &capacity, 21);

    printf("Capacity: %d\n", capacity);
    printf("Last index: %d\n", last_index);
    printf("First element: %d\n", arr[0]);
    printf("Last element: %d\n", arr[last_index - 1]);
    free(arr);
    return 0;
}