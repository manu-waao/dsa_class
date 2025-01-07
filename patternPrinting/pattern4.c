#include <stdio.h>
void main(){
    for(int i = 0; i <= 9; i++){
        for(int j =0; j <= i; j+=2){
            printf(" ");
        }
        int x = 1;
        while(x <= 9-i){
            if(i%2 != 0){
                x++;
                continue;
            }
            else{
                printf("*");
            }
            x++;
        }
        printf("\n");
    }
}