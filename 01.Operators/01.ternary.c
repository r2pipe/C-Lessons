#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    x > y ? printf("%d\n", x) : printf("%d\n", y); //ternary operator əsasən dəyər (value) seçmək üçün nəzərdə tutulub, əməliyyat (action) etmək üçün yox

    //şərt ? doğru hal : səhv hal
    //int max = x > y ? x : y; //daha yaxşı istifadə nümunəsi belədir
    /* if(x>y){
        max = x;
    }else{
        max = y;
    }*/
    //printf("Max number %d", max);

    return 0;
}