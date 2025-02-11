#include <stdio.h>
void main(){
    printf("Enter the number of elements: \n");
    int size, tmp;
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements: \n");
    for (int i = 0; i < size; i++){
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
    
    for (int i = 0; i < size / 2; i++) {
        tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }

    for(int x = 0; x < 3; x++){
        printf("%d", arr[x]);
    }
}
