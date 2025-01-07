#include <stdio.h>
void main() {
    for(int i = 1; i <= 5; i++){ 
        printf("%*s", 5 - i, "");     
        for(int x = 1; x <= (2 * i - 1); x++) {
            if(x <= i){
                printf("%d", x);     
            } else{
                printf("%d", 2 * i - x);  
            }
        }
        printf("\n");
    }
}
