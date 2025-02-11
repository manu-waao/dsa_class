#include <stdio.h>
void main(){
    int size1, size2, counter;
    printf("Enter the number of elememts : size1 size2\n");
    scanf("%d %d", &size1, &size2);
    int arr[size1][size2];
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(arr[i][j] != 0){
                counter++;
            }
        }
    }
    printf("%d", counter);
}