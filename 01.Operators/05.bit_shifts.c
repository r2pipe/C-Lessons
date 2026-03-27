#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// unsigned int: mənfi dəyərləri ala bilməyən tam ədəd tipidir
// signed int: mənfi və müsbət dəyərləri ala bilən tam ədəd tipidir
int main(int argc, char* argv[]){

    // -----------------------------
    // Unsigned left shift
    // a << n → a × 2ⁿ
    // Heç bir mənfi dəyər yaranmır
    // Bit vizualı: 00000000 00000000 00000000 00000001 → sola shift
    // -----------------------------
    unsigned int ua = 1;
    printf("Unsigned left shifted by 1: %d\n", ua << 1); // 1*2 = 2
    printf("Unsigned left shifted by 2: %d\n", ua << 2); // 1*4 = 4
    printf("Unsigned left shifted by 3: %d\n", ua << 3); // 1*8 = 8

    // -----------------------------
    // Signed left shift
    // a << n → a × 2ⁿ (mənfi və müsbət üçün)
    // Overflow ola bilər, diqqətli olmaq lazımdır
    // -----------------------------
    int sa = 1;
    printf("Signed left shifted by 1: %d\n", sa << 1); // 1*2 = 2
    printf("Signed left shifted by 2: %d\n", sa << 2); // 1*4 = 4
    printf("Signed left shifted by 3: %d\n", sa << 3); // 1*8 = 8

    // -----------------------------
    // Unsigned right shift
    // a >> n → a / 2ⁿ
    // Soldan 0 gəlir, heç bir mənfi dəyər yaranmır
    // -----------------------------
    unsigned int ur = 8;
    printf("Unsigned right shifted by 1: %d\n", ur >> 1); // 8/2 = 4
    printf("Unsigned right shifted by 2: %d\n", ur >> 2); // 8/4 = 2
    printf("Unsigned right shifted by 3: %d\n", ur >> 3); // 8/8 = 1

    // -----------------------------
    // Signed right shift
    // a >> n → a / 2ⁿ (mənfi və müsbət üçün)
    // Arithmetic shift → işarə biti qorunur
    // -----------------------------
    int sr = 8;
    int sr_neg = -8;
    printf("Signed right shifted by 1 (positive): %d\n", sr >> 1); // 8/2 = 4
    printf("Signed right shifted by 2 (positive): %d\n", sr >> 2); // 8/4 = 2
    printf("Signed right shifted by 3 (positive): %d\n", sr >> 3); // 8/8 = 1

    printf("Signed right shifted by 1 (negative): %d\n", sr_neg >> 1); // -8/2 = -4
    printf("Signed right shifted by 2 (negative): %d\n", sr_neg >> 2); // -8/4 = -2
    printf("Signed right shifted by 3 (negative): %d\n", sr_neg >> 3); // -8/8 = -1

    puts("\n\n");

     unsigned int a = 5; // unsigned left/right shift üçün

    int i;
    printf("Unsigned left shift:\n");
    for(i = 0; i < 32; i++){
        printf("Left shifted by %02d: %08x | %u\n", i, a << i, a << i);
    }

    puts("\nUnsigned right shift:\n");
    int j;
    for(j = 0; j < 32; j++){
        printf("Right shifted by %02d: %08x | %u\n", j, a >> j, a >> j);
    }

    // Signed right shift nümunəsi
    int saa = 5;
    int saa_neg = -5;
    puts("\nSigned right shift (positive):\n");
    for(j = 0; j < 32; j++){
        printf("%02d: %08x | %d\n", j, saa >> j, saa >> j);
    }

    puts("\nSigned right shift (negative):\n");
    for(j = 0; j < 32; j++){
        printf("%02d: %08x | %d\n", j, saa_neg >> j, saa_neg >> j);
    }

    return 0;
}

/*
Unsigned vs signed fərqi:
- Unsigned: yalnız 0-dan yuxarı dəyərləri ala bilər.
  - Solda left shift zamanı overflow ola bilər (yəni bitlər 32-bit-dən çıxsa itir).
  - Sağa right shift → boş yerlərə 0 əlavə olunur (logical shift), mənfi dəyər olmaz.
- Signed: həm müsbət, həm mənfi dəyərləri ala bilir.
  - Left shift → overflow riski var (mənfi və müsbət üçün).
  - Right shift → arithmetic shift, yəni işarə biti qorunur.
    - Müsbət üçün soldan 0 əlavə olunur.
    - Mənfi üçün soldan 1 əlavə olunur.

Left shift (<<):
- a << n → a × 2ⁿ (riyazi baxımdan)
- Binary-də bitlər sola sürüşdürülür.
- Boş sağ bitlər 0 ilə doldurulur.
- Unsigned overflow → bitlər itir.
- Signed overflow → nəticə undefined ola bilər, diqqətli olmaq lazımdır.

Right shift (>>):
- Unsigned → a / 2ⁿ
  - Soldan 0 əlavə olunur (logical shift)
- Signed → a / 2ⁿ
  - Arithmetic shift: işarə biti qorunur
    - Müsbət → soldan 0
    - Mənfi → soldan 1

Formatlar:
- Hex (%08x) → 0/1-ləri və overflow-u vizual görmək üçün, 8 simvollu, başında 0-larla doldurulur
- Decimal (%u/%d) → riyazi nəticə göstərir
  - %u → unsigned decimal
  - %d → signed decimal

Əsas fikir:
- Shift operatorları bitləri sürüşdürmək üçün birbaşa yol.
- Riyazi baxımdan left shift → 2-yə vurma, right shift → 2-yə bölmə kimi düşünülə bilər.
*/