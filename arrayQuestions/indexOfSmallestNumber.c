#include <stdio.h>
void main(){
    int arr[5];
    for(int i = 0; i<5; i++){
        scanf("%d", &arr[i]);
    }
    int smallest = arr[0];
    int index;
    for(int j = 0; j < 5; j++){
        if(smallest > arr[j]){  
            smallest = arr[j];
            index = j;
        }
    }
    printf("Smallest number is at index number : %d", index);
}