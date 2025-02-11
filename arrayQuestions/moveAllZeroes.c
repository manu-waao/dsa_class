#include <stdio.h>
void main(){
    int size, j;
    printf("Enter size of array: \n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: \n");
    for(j = 0; j < size; j++){
        scanf("%d", &arr[j]);
    }
    j = 0; 
    for(int i = 0; i < size; i++){
        if(arr[i] != 0){
            arr[j] = arr[i];
            j++;
        }
    }
    for(int i = j; i < size; i++){
        arr[i] = 0;
    }
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
