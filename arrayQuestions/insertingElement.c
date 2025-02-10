#include <stdio.h>
#include <stdlib.h>
void main(){
    int arr[6] = {}; 
    printf("Enter 6 elements in the array : \n");
    for(int x = 0; x <6; x++){
        scanf("%d", &arr[x]);
    }
    printf("Enter element to insert and index of element : ");
    int element, index;  
    scanf("%d %d", &element, &index);
    int size = 6;
    if (index < 0 || index > size) {
        printf("Invalid index.\n");
        exit(0);
    }
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    size++;
    printf("Array after insertion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
