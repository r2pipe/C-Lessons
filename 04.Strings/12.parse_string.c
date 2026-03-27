#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    // Input string: ad;şəhər;yaş;degree (0/1)
    char str[] = "Andrew;New York;20;0";

    // Buffers üçün ölçülər müəyyən edirik, +1 '\0' üçün , { 0 } → array-in bütün elementlərini sıfırla deməkdir.
    char name[20] = { 0 };   // Ad üçün buffer
    char city[20] = { 0 };   // Şəhər üçün buffer
    unsigned int age;        // Yaş üçün unsigned int
    int hasDegree;           // Diplom var/yoq (int)

    // sscanf ilə stringi parçalayırıq
    // %19[^;] → ; görənə qədər maksimum 19 simvol oxu (son simvol '\0' üçün ayrılır)
    // %u → unsigned int üçün
    // %d → int üçün
    int parsed = sscanf(str, "%19[^;];%19[^;];%u;%d", name, city, &age, &hasDegree);

    // Parsing uğurlu olub olmadığını yoxlayırıq
    if (parsed != 4) {
        fprintf(stderr, "Parsing error! Expected 4 values but got %d\n", parsed);
        return 1;
    }

    printf("%s is in %s, is %u years old, has degree: %d\n", name, city, age, hasDegree);

    return 0;
}