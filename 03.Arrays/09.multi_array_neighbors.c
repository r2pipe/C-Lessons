#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

    // 5x5 ikiölçülü array tərifi
    // arr[y][x] ilə istənilən elementi çağırmaq olar
    int arr[][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
    };

    // Qonşulara getmək üçün x və y istiqamətində addım göstəriciləri (offset-lər)
    // Bu dəfə **8 istiqamət** üçün: yuxarı, yuxarı-sağ, sağ, aşağı-sağ, aşağı, aşağı-sol, sol, yuxarı-sol
    int offsetx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int offsety[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    int x, y;

    // İstifadəçidən başlanğıc koordinatları soruşuruq
    printf("Input x:");
    scanf("%d", &x);
    printf("Input y:");
    scanf("%d", &y);

    // sum dəyişəni seçilmiş elementi ilə başlayır
    int sum = arr[y][x];

    // 8 qonşunu iterasiya edirik
    for(int i = 0; i < 8; i++){
        int nx = x + offsetx[i];  // qonşunun x koordinatı
        int ny = y + offsety[i];  // qonşunun y koordinatı

        // Kənarlarda çıxmamaq üçün yoxlama
        if(nx < 0 || nx > 4 || ny < 0 || ny > 4){
            continue; // əgər kənardadırsa, növbəti qonşuya keç
        }

        // Qonşunun dəyərini sum-a əlavə et
        sum += arr[ny][nx];
    }

    // Son nəticəni çap edirik
    printf("The sum is %d\n", sum);

    return 0;
}