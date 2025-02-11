#include <stdio.h>
void main(){
    int tmp, size;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &size);
    int arr[size];

    for(int j = 0; j < size; j++){
        scanf("%d", &arr[j]);
    }

    for (int i = 0; i < size / 2; i++) {
        tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }
    
    for(int x = 0; x < size; x++){
        printf("%d", arr[x]);
    }
}