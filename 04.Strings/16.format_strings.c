#include <stdio.h>
#include <stdlib.h>

#define POINT_FORMAT "(%d, %d)" // printf və snprintf üçün format string-i təkrar yazmamaq üçün macro; dəyişiklik olsa tək yerdən edilir

typedef struct Point{
    int x, y; // 2 ölçülü koordinat üçün struktur sahələri
} Point;

void process(Point q){ // Point strukturu copy olaraq ötürülür (pass-by-value), original dəyişmir

    q.x += 5; // yalnız copy dəyişir, main-dəki p.x dəyişməyəcək

    printf(POINT_FORMAT"\n", q.x, q.y); // macro istifadə edərək koordinatı çap edir
}

int main(int argc, char* argv[]){

    Point p = { // designated initializer: struktur sahələrini birbaşa ad ilə initialize edirik
        .x = 10,
        .y = 25
    };

    char buf[100]; // format edilmiş stringi saxlamaq üçün buffer (snprintf buraya yazacaq)

    process(p); // funksiyaya copy göndərilir, original p dəyişməyəcək

    snprintf(buf, 100, POINT_FORMAT"\n", p.x, p.y); // format edilmiş stringi buf daxilinə yazır (overflow riskini ölçü limiti ilə azaldır)

    printf("%s", buf); // buffer daxilində saxlanan stringi ekrana çap edir

    return 0;
}