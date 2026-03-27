#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

    int matrix[5][5] = {
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    };

    printf("FULL MATRIX:\n");

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    printf("\nMAIN DIAGONAL:\n");

    for(int i = 0; i < 5; i++){
        printf("%d ", matrix[i][i]);
    }


    printf("\n\nSECONDARY DIAGONAL:\n");

    for(int i = 0; i < 5; i++){
        printf("%d ", matrix[i][4 - i]);
    }


    printf("\n\nUPPER TRIANGLE:\n");

    for(int i = 0; i < 5; i++){
        for(int j = i; j < 5; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    printf("\nLOWER TRIANGLE:\n");

    for(int i = 0; i < 5; i++){
        for(int j = 0; j <= i; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    printf("\nBORDER ELEMENTS:\n");

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == 0 || i == 4 || j == 0 || j == 4){
                printf("%d ", matrix[i][j]);
            }
        }
    }


    printf("\n\nROW SUMS:\n");

    for(int i = 0; i < 5; i++){

        int sum = 0;

        for(int j = 0; j < 5; j++){
            sum += matrix[i][j];
        }

        printf("Row %d sum = %d\n", i, sum);
    }


    printf("\nCOLUMN SUMS:\n");

    for(int j = 0; j < 5; j++){

        int sum = 0;

        for(int i = 0; i < 5; i++){
            sum += matrix[i][j];
        }

        printf("Column %d sum = %d\n", j, sum);
    }


    printf("\nCENTER ELEMENT:\n");

    printf("%d\n", matrix[2][2]);


    return 0;
}