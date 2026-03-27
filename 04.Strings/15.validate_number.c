#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>  // errno və ERANGE makrolarını istifadə etmək üçün

int main(int argc, char* argv[]){
    // Pars ediləcək böyük string ədəd
    char str[100] = "13333333333333333333333333333333333333333333333333333";

    // strtol funksiyası üçün oxunmayan hissəni saxlamaq məqsədilə pointer
    char* endPtr;

    /**
     * strtol: string → long int
     * parametrlər:
     *   str → çevriləcək string
     *   &endPtr → oxuma zamanı dayanılan yerin pointeri
     *   10 → decimal ədəd sistemi
     * qayıdan dəyər → çevrilmiş long int
     */
    long int x = strtol(str, &endPtr, 10);

    // Əgər heç bir rəqəm oxunmayıbsa
    if(str == endPtr){
        printf("Number could not be parsed!\n");
        return 0;
    }

    // Əgər ədəd long int-in limitini aşırsa
    if(errno == ERANGE){
        printf("Number is too big to store in the variable!\n");
        return 0;
    }

    // Əgər hər şey düzgündürsə, nəticəni çap et
    printf("%ld\n", x);

    return 0;
}