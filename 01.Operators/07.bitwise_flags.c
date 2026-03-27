#include <stdlib.h>
#include <stdio.h>

// Hər bir bit üçün mənalı adlar təyin edirik
#define FIRST_FLAG  0b1        // 1-ci bit → 1st feature
#define SECOND_FLAG 0b10       // 2-ci bit → 2nd feature
#define THIRD_FLAG  0b10000000 // 8-ci bit → 3rd feature

int main(int argc, char* argv[]){

    // Bütün feature-ları bir dəyişəndə birləşdiririk
    // OR (|) operatoru hər bitdən ən azı biri 1dirsə 1 qoyur
    unsigned int flags = FIRST_FLAG | SECOND_FLAG | THIRD_FLAG; 
    // Nəticədə flags = 0b10000011 → 1,2 və 8-ci bit aktivdir

    // İndi SECOND_FLAG-i (2-ci feature) deaktiv edək
    flags = flags & ~SECOND_FLAG; // ~SECOND_FLAG = 0b11111101 → AND ilə 2-ci biti 0 edirik


    // 1-ci feature-i yoxlayırıq
    // flags & FIRST_FLAG → 1-ci bit aktivdirsə non-zero olacaq
    if(flags & FIRST_FLAG){
        printf("1st featured is enabled\n");
    }

    // 2-ci feature-i yoxlayırıq
    // flags & SECOND_FLAG → 2-ci bit aktivdirsə non-zero olacaq
    if(flags & SECOND_FLAG){
        printf("2nd featured is enabled\n");
    }

    // 3-cü feature-i yoxlayırıq
    // flags & THIRD_FLAG → 8-ci bit aktivdirsə non-zero olacaq
    if(flags & THIRD_FLAG){
        printf("3rd featured is enabled\n");
    }

    return 0; 
}