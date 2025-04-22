#include <stdio.h>
void main(void){
    printf("Enter the size of array : ");
    int sz, val;
    scanf("%d", &sz);
    int arr[sz];
    for(int i =0; i < sz; i++){
        printf("enter val : ");
        scanf("%d", &val);
        arr[i] = val;
    }
    for(int i = 0; i < sz; i++){
        printf("%d", arr[i]);
    }

    
}