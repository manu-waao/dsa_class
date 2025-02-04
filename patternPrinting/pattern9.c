#include <stdio.h>
void main(){
    for(int i = 1; i <= 5; i++){
        for(int p = 1; p <= 5 - i; p++){
            printf(" ");
        }
        for(int j = 1; j <= (2 * i - 1); j++){
            printf("*");
        }
        printf("\n");
    }

    for(int i = 5 - 1; i >= 1; i--){
        for(int p = 1; p <= 5 - i; p++){
            printf(" ");
        }
        for(int j = 1; j <= (2 * i - 1); j++){
            printf("*");
        }
        printf("\n");
    }
}
