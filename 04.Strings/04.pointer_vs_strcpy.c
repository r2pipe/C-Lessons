#include <stdlib.h>   
#include <stdio.h>   
#include <string.h>   

char* str;   
int num;             

void create(){
    num = 100;
    str = malloc(sizeof(char) * num);  // heap-də 100 byte ayırırıq, str indi heap memory göstərir                                       
}

void process(){
    char example[100] = "This is a test";  // stack-də local array, process() bitəndə yox olacaq
                                           
    //str = example;  
    // Bu yanlış olardı: str stack-dəki example array-a yönəlir
    // → heap pointer-i itiririk (memory leak)
    // → printf işləyə bilər, amma str dangling pointer olur
    // → free(str) çağırmaq crash / corruption yaradır

    strcpy(str, example);  
    // Burada example-in məzmunu heap-dəki str-ə kopyalanır
    // → stack və heap ayrılıb
    // → printf təhlükəsiz işləyir
    // → free(str) artıq təhlükəsizdir
    printf("%s\n", str);
}

int main(int argc, char* argv[]){
    create();      
    process();     
    free(str);     
    return 0;
}