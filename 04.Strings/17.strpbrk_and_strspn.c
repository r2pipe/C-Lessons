#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    
    char str[] = "Daniel is 25 years old";   
    char* age = strpbrk(str, "0123456789"); // str içində ilk dəfə rast gəlinən rəqəmin adresini tapır və pointer qaytarır
                                            // nəticə: age -> "25 years old" hissəsinin başlanğıcını göstərir

    printf("%s\n", age);
                            
    for(int i = 0; i < strspn(age, "0123456789"); i++){ // age stringinin əvvəlindən başlayaraq neçə dənə ardıcıl rəqəm olduğunu sayır
                                                        // burada nəticə: 2 (çünki "25")
        printf("%c", age[i]); // yalnız tapılan rəqəmləri bir-bir çap edir
    }

    printf("\n"); 

    return 0; 
}

/*
Bu nümunədə strpbrk və strspn funksiyaları birlikdə istifadə olunur ki, string içindən rəqəmləri tapıb çıxarmaq mümkün olsun.

1️⃣ strpbrk(str, "0123456789")
   - str stringində ilk dəfə rast gəlinən rəqəmi tapır.
   - Pointer qaytarır: ilk rəqəmin ünvanına işarə edir.
   - Misal: "Daniel is 25 years old" stringində ilk rəqəm '2' olduğu üçün age pointer-i "25 years old"-a yönəldir.

2️⃣ printf("%s\n", age)
   - Pointer-in göstərdiyi stringi çap edir.
   - Nəticə: "25 years old"

3️⃣ strspn(age, "0123456789")
   - Pointer-in göstərdiyi hissənin başlanğıcından başlayaraq neçə ardıcıl uyğun simvol olduğunu sayır.
   - Burada uyğun simvol = rəqəm ('0'-'9').
   - Misal: "25 years old" → 2 simvol ardıcıl rəqəm var → nəticə: 2

4️⃣ for döngüsü
   - 0-dan strspn nəticəsinə qədər dövr edir.
   - Hər iterasiyada age[i] çap olunur.
   - Nəticədə yalnız rəqəmlər çıxarılır: "25"

Qısa qayda:
- strpbrk → harada başlamaq lazım olduğunu tapır (ilk uyğun simvol)
- strspn  → başlanğıcdan neçə simvol uyğun olduğunu ölçür
- Bu iki funksiyanı birlikdə istifadə etmək string parsing-də, input analizi və rəqəm çıxarmaq üçün klassik üsuldur.

Əgər strpbrk istifadə etməsəydik və birbaşa strspn(str, "0123456789") etsəydik:
- str stringinin başlanğıcında rəqəm olmadığı üçün nəticə 0 olardı.
- Ona görə strpbrk öncə pointer-i rəqəmin olduğu yerə aparır, sonra strspn neçə rəqəm olduğunu ölçür.
*/