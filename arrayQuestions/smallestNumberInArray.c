#include <stdio.h>
void main(){
    int arr[6];
    int smallest;
    for(int j = 0; j < 6; j++){
        scanf("%d", &arr[j]);
    }
    smallest = arr[0];
    for(int i = 1; i < 6; i++){
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    printf("The smallest number is: %d\n", smallest);
}
