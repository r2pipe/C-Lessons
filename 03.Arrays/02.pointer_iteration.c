#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){
    int arr[] = {7, 8, 9, 10, 11};
    int n = 5;
    printf("Start address: %p\nEnd address: %p\n", &arr[0], &arr[4]);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    // p++ => p = p + 1 * sizeof(type)
    for(int *p = arr; p <= &arr[4]; p++){ // C-də array adını yazanda avtomatik başlanğıc ünvan kimi qəbul olunur => &arr[0]
        printf("Value: %d, Address: %p\n", *p, (void*)p);
    }

    return 0;
}

