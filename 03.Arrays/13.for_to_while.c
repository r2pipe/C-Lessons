#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    i = 0;
    while(i < n){
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");

    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    i = -1;
    while(++i < n){
        printf("%d ", arr[i]);

    }

    return 0;
}