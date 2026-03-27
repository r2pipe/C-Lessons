#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// Bu funksiya str array-ini uzunluğu num qədər random kiçik hərflərlə doldurur
void rand_string(char* str, int num){
    for(int i = 0; i < num; i++){                           // 0-dan num-1-ə qədər loop
        str[i] = rand() % ('z' - 'a' + 1) + 'a';           // 0-25 arası random → 'a'-'z'
    }
    str[15] = 0;                                           // son simvolu '\0' edirik
}

int main(int argc, char* argv[]){
    srand(time(NULL));                                     // random generator üçün seed
    char str[16];                                          // 15 simvol + 1 '\0' üçün yer
    rand_string(str, 15);                                  // random 15 simvollu string yaradır
    printf("%s\n\n", str);                                 // yaradılmış random stringi çap edir
    return 0;                                              // proqram normal bitir
}

// şifrə, token, cryptography üçün heç vaxt rand() istifadə etməyin.
// rand() əsl random deyil, sadəcə əvvəlcədən təyin olunmuş formula ilə sayı hesablayır.
// Hər dəfə eyni seed (srand) ilə eyni nəticə alınır → hacker-lər bunu asanlıqla təxmin edə bilər.