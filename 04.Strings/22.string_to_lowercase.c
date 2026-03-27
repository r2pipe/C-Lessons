#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

int main(int argc, char* argv[]){
    char str[] = "This is an EXAMPLE String";         // orijinal string
    size_t length = strlen(str);                      // string uzunluğunu ölçür

    // int diff = ('a' - 'A');                        // ASCII fərqi ilə əl ilə çevirmə variantı

    for(size_t i = 0; i < length; i++){              // bütün simvollar üzərində döngü
        // if(str[i] >= 'A' && str[i] <= 'Z'){       // əl ilə böyük hərfi kiçik hərfə çevirə bilərik
        //     str[i] += diff;
        // }

        if(isupper(str[i])){                         // əgər simvol böyük hərfdirsə
            str[i] = tolower(str[i]);                // onu kiçik hərfə çevirir
        }
    }

    printf("Result is: '%s'\n", str);               
    return 0;                                       
}