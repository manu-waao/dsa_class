#include <stdio.h>
int sumOfElements(int arr[], int i) {
    if (arr[i] == '\0') {
        return 0;
    }
    return arr[i] + sumOfElements(arr, i + 1);
}

int main() {
    int num;
    printf("Enter the number of elements : \n");
    scanf("%d", &num);
    int arr[num];
    for(int j = 0; j < num; j++){
        scanf("%d", &arr[j]);
    }
    
    int result = sumOfElements(arr, 0);
    printf("Sum of all elements: %d\n", result);
    
    return 0;
}
