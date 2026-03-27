#include <stdio.h>
#include <stdlib.h>

void fibo(int k){
    // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 - fibonacci series
    int n1, n2, x;
    int i;
    n1 = 0;
    n2 = 1;
    for(i = 0; i< k - 2; i++){
        x = n2;
        n2 = n1 + n2;
        n1 = x;
    }printf("The %dth number: %d\n", k, n2);
}

int main(int argc, char* argv[]){
    
    fibo(20);
    fibo(200);
    return 0;
}