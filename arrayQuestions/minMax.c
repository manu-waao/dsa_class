#include <stdio.h>
void main(){
    int size, cnt = 0;
    printf("Enter the number of elements : \n");
    scanf("%d", &size);
    int arr[size];
    int arr2[size];
    for(int x = 0; x < size; x++){
        scanf("%d", &arr[x]);
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

    int pointerPos = 0, pointerNeg = size-1;
    do {
        arr2[cnt] = arr[pointerNeg];
        cnt++;
        if (cnt == size) break;
        arr2[cnt] = arr[pointerPos];
        pointerPos++;
        pointerNeg--;
        cnt++;
        
    }
    while(cnt != size);
    
    for(int p = 0; p < size; p++){
        printf("\n%d", arr2[p]);

    }
}
