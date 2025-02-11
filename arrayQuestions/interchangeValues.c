#include <stdio.h>
void main(){
    int size;
    printf("Enter the number of elements : \n");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int temp;
    temp = arr[1];   
    arr[1] = arr[size-2];
    arr[size-2] = temp;
    for(int x = 0; x < size; x++){
        printf("%d", arr[x]);
    }
}